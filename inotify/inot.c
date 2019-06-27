/*
 * Example usage of inotify to watch changes in the file system.
 *
 * https://www.linuxjournal.com/article/8478
 */

#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <sys/inotify.h>

/* size of the event structure, not counting name */
#define EVENT_SIZE  (sizeof (struct inotify_event))

/* reasonable guess as to size of 1024 events */
#define BUF_LEN        (1024 * (EVENT_SIZE + 16))

int main() {

    int fd, wd;

    /* initialise an inotify instance in the kernel*/

    fd = inotify_init();
    if (fd < 0)
	perror("inotify_init");

    /* add a watch to a file system target:
     *
     *   int inotify_add_watch (int fd, const char *path, __u32 mask);
     *
     * valid masks are: 
     * IN_ACCESS	  File was read from.
     * IN_MODIFY	  File was written to.
     * IN_ATTRIB	  File's metadata (inode or xattr) was changed.
     * IN_CLOSE_WRITE	  File was closed (and was open for writing).
     * IN_CLOSE_NOWRITE	  File was closed (and was not open for writing).
     * IN_OPEN	          File was opened.
     * IN_MOVED_FROM	  File was moved away from watch.
     * IN_MOVED_TO        File was moved to watch.
     * IN_DELETE          File was deleted.
     * IN_DELETE_SELF     The watch itself was deleted.
     * IN_CLOSE	          IN_CLOSE_WRITE | IN_CLOSE_NOWRITE
     * IN_MOVE	          IN_MOVED_FROM | IN_MOVED_TO
     * IN_ALL_EVENTS	  Bitwise OR of all events.
     */
    wd = inotify_add_watch(fd,
			   "/home/raf/tmp",
			   IN_MODIFY | IN_CREATE | IN_DELETE);
    if (wd < 0)
	perror("inotify_add_watch");

    /* receiving events
     * Events are delivered in the form of an inotify_event structure, 
     * which is defined as:
     *
     *   struct inotify_event {
     *       __s32 wd;             /* watch descriptor /
     *       __u32 mask;           /* watch mask /
     *       __u32 cookie;         /* cookie to synchronize two events /
     *       __u32 len;            /* length (including nulls) of name /
     *       char name[0];        /* stub for possible name /
     *   };
     */

    char buf[BUF_LEN];
    int len, i;

    /* this call will block until an event is received */
    len = read (fd, buf, BUF_LEN);

    if (len < 0) {
	
	if (errno == EINTR)
	    /* need to reissue system call */
	    printf("what now?\n");
	else
	    perror ("read");
    } else if (!len)
	/* BUF_LEN too small? */
	printf("what now?\n");
    
    i = 0;
    while (i < len) {
	struct inotify_event *event;

	event = (struct inotify_event *) &buf[i];
	
	printf ("wd=%d mask=%u cookie=%u len=%u\n",
		event->wd, event->mask,
		event->cookie, event->len);
	    
	if (event->len)
	    printf ("name=%s\n", event->name);

	i += EVENT_SIZE + event->len;
    }
	    


    /* tidy up shit*/
    int ret;
    ret = close(fd);
    if (ret)
	perror("close");

    return 0;
}
