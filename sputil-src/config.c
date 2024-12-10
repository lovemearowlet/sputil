/*
 *               Config File: This is to config the utility! (its all CaSe SeNsItIvE)
 *               It has C syntax and if you know C it can be used to add stuff! 
 *               (type) (name) = (value); is how the things go for ppl new to C.
 *               I also included a example below.
 */

/* this is to set the super user command. default is sudo. it does not support su -c btw (it can but needs main file configing!).*/
// superuser command example: static const char superuser = "sudo";
static const char superuser[256] = "sudo";

/* this is the install, uninstall, and update (you can tell by the name) args for your distro. default is void.*/

// install example: static const char installarg = "xbps-install -Sv";
static const char installarg[256] = "xbps-install -Sv";

// uninstall example: static const char unstallarg = "xbps-remove -Rv";
static const char unstallarg[256] = "xbps-remove -Rv";

// update example: static const char updatearg = "xbps-install -Suv";
static const char updatearg[256] = "xbps-install -Suv";

