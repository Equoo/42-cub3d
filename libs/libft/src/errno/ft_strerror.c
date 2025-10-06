/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strerror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 20:51:07 by dderny            #+#    #+#             */
/*   Updated: 2025/04/02 20:51:08 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>

static char	*ft_strerror5(int err)
{
	if (err == EMSGSIZE)
		return ("Message too long");
	if (err == ENETDOWN)
		return ("Network is down");
	if (err == ENETRESET)
		return ("Network dropped connection because of reset");
	if (err == EADDRNOTAVAIL)
		return ("Address not available");
	if (err == EAFNOSUPPORT)
		return ("Address family not supported");
	if (err == EALREADY)
		return ("Operation already in progress");
	if (err == EBADF)
		return ("Bad file descriptor");
	return ("Unknown error");
}

static char	*ft_strerror4(int err)
{
	if (err == ESHUTDOWN)
		return ("Cannot send after transport endpoint shutdown");
	if (err == ESRCH)
		return ("No such process");
	if (err == EXDEV)
		return ("Cross-device link");
	if (err == EAGAIN)
		return ("Resource temporarily unavailable");
	if (err == EDEADLK)
		return ("Resource deadlock avoided");
	if (err == EDESTADDRREQ)
		return ("Destination address required");
	if (err == EDQUOT)
		return ("Disk quota exceeded");
	if (err == EHOSTDOWN)
		return ("Host is down");
	if (err == EHOSTUNREACH)
		return ("No route to host");
	if (err == EINPROGRESS)
		return ("Operation now in progress");
	if (err == ELOOP)
		return ("Too many levels of symbolic links");
	if (err == EMLINK)
		return ("Too many links");
	return (ft_strerror5(err));
}

static char	*ft_strerror3(int err)
{
	if (err == EBUSY)
		return ("Device or resource busy");
	if (err == ECHILD)
		return ("No child processes");
	if (err == EDOM)
		return ("Mathematics argument out of domain of function");
	if (err == EFBIG)
		return ("File too large");
	if (err == EISCONN)
		return ("Socket is already connected");
	if (err == ENOTSOCK)
		return ("Not a socket");
	if (err == ENOTTY)
		return ("Inappropriate ioctl for device");
	if (err == EOPNOTSUPP)
		return ("Operation not supported on socket");
	if (err == EOVERFLOW)
		return ("Value too large for defined data type");
	if (err == EPROTO)
		return ("Protocol error");
	if (err == EPROTONOSUPPORT)
		return ("Protocol not supported");
	if (err == EPROTOTYPE)
		return ("Protocol wrong type for socket");
	return (ft_strerror4(err));
}

static char	*ft_strerror2(int err)
{
	if (err == ENOSPC)
		return ("No space left on device");
	if (err == ENOTDIR)
		return ("Not a directory");
	if (err == EPERM)
		return ("Operation not permitted");
	if (err == EPIPE)
		return ("Broken pipe");
	if (err == EROFS)
		return ("Read-only file system");
	if (err == ESPIPE)
		return ("Illegal seek");
	if (err == ETIMEDOUT)
		return ("Connection timed out");
	if (err == EWOULDBLOCK)
		return ("Operation would block");
	if (err == ECONNRESET)
		return ("Connection reset by peer");
	if (err == ECONNREFUSED)
		return ("Connection refused");
	if (err == ECONNABORTED)
		return ("Connection aborted");
	if (err == EADDRINUSE)
		return ("Address already in use");
	return (ft_strerror3(err));
}

char	*ft_strerror(int err)
{
	if (err == EACCES)
		return ("Permission denied");
	if (err == EEXIST)
		return ("File exists");
	if (err == EFAULT)
		return ("Bad address");
	if (err == EINTR)
		return ("Interrupted system call");
	if (err == EINVAL)
		return ("Invalid argument");
	if (err == EIO)
		return ("I/O error");
	if (err == EISDIR)
		return ("Is a directory");
	if (err == EMFILE)
		return ("Too many open files");
	if (err == ENAMETOOLONG)
		return ("File name too long");
	if (err == ENFILE)
		return ("File table overflow");
	if (err == ENOENT)
		return ("No such file or directory");
	if (err == ENOMEM)
		return ("Out of memory");
	return (ft_strerror2(err));
}
