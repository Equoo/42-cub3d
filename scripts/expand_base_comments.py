#!/usr/bin/env python3

import argparse
import re
import sys
from pathlib import Path
from typing import Dict, List, Tuple

COMMENT_RE = re.compile(r"/\*\*\s*INHERIT\s*(?P<parent>\w+)\s*\*\*/\s*typedef\s*struct\s*s_(?P<class>\w+)\s*t_\w+;\s*struct\s*s_\w+\s*{\n(?P<body>.*?)\n};", re.DOTALL)

def find_classes(root: Path) -> Dict[str, Tuple[str, str, str, List[str]]]:
    mapping: Dict[str, Tuple[str, str, str, List[str]]] = {}
    for path in root.rglob("*.hpp"):
        text = path.read_text(encoding="utf-8")
        for m in COMMENT_RE.finditer(text):
            parent = m.group("parent")
            classname = m.group("class")
            body = m.group("body")
            mapping[classname] = (parent, body, "", [])
    return mapping

def do_inheritage(classes: Dict[str, Tuple[str, str, str, List[str]]], inherit_parent: str):
    for name, (parent, body, inherited, parents) in classes.items():
        if parent != inherit_parent:
            continue
        inherited = classes[parent][2] + "\n" + classes[parent][1]
        parents = classes[parent][3] + [parent]
        classes[name] = (parent, body, inherited, parents)
        classes = do_inheritage(classes, name)
    return classes

def expand_in_file(path: Path, classes: Dict[str, Tuple[str, str, str, List[str]]]) -> List[Tuple[int,str,str]]:
    original = path.read_text(encoding="utf-8")
    new_path = path.with_suffix(".h")
    previews: List[Tuple[int,str,str]] = []

    text = original
    
    for m in COMMENT_RE.finditer(text):
        parent = m.group("parent")
        name = m.group("class")
        if name == "object":
            text = COMMENT_RE.sub(m[0].replace("t_self", "t_object"), text)
            continue

        body = classes[name][1].replace("t_self", f"t_{name}")
        inherited = classes[name][2].replace("t_self", f"t_{name}")
        parents = classes[name][3]

        new_body = f"/** INHERIT {parent} **/\ntypedef struct s_{name} t_{name};\nstruct s_{name}\n{{\n\tunion {{\n"

        for prnt in parents:
            new_body = new_body + f"\t\tt_{prnt}\t{prnt};\n"

        new_body = new_body + f"\t\tstruct {{{inherited}\n\t\t}};\n\t}};\n{body}\n}};"

        text = COMMENT_RE.sub(new_body, text)
        previews.append((0, name, f"1 replacements"))

	############## THEN FORMAT

    new_path.write_text(text, encoding="utf-8")
    return previews


def main():
    root = Path(".")
    classes = find_classes(root)
    if not classes:
        print("No classes found.")
        return

    print(f"Found {len(classes)} classes block(s): {', '.join(classes.keys())}")

    classes = do_inheritage(classes, "object")

    total_changes = 0
    for path in root.rglob("*.hpp"):
        previews = expand_in_file(path, classes)
        if previews:
            print(f"{path}: ")
            for p in previews:
                print(f"  - {p[1]} -> {p[2]}")
            total_changes += sum(int(p[2].split()[0]) for p in previews)

    print(f"Total replacements: {total_changes}")

if __name__ == '__main__':
    main()
