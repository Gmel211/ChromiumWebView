#ifndef WEBVIEW_H
#define WEBVIEW_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

#define URL 300
#define DOCUMENT 900


typedef struct {
    int width;
    int height;
} JWindowSize;

typedef struct {
    char title[128];
    int AddressBar;
    int FullScreen;
    int Incognito;
    int KioskMode;
    int DisableGPU;
    int Zoom;
    JWindowSize WindowSize;
} JWindowSettings;

typedef struct {
    int Ctype;
    char buffer[2048];
} JDisplayContent;

typedef enum {
    RELOADWINDOW = 0,
    BACK = 1,
    FORWARD = 2,
    CLOSETAB = 3
} JSignal;

typedef enum {
    ADDRESSBAR = 1,
    FULLSCREEN = 1,
    INCOGNITO = 1,
    KIOSKMODE = 1,
    ENABLE_GPU = 1,
    CHROMIUM_LOGS =1,
    DEBUG = 1,
    JEB_LOG = true,
    NO_ADDRESSBAR = 0,
    NO_FULLSCREEN = 0,
    NO_INCOGNITO = 0,
    NO_KIOSKMODE = 0,
    DISABLE_GPU = 0,
    NO_CHROMIUM_LOGS = 0,
    NO_DEBUG = 0,
    NO_WEBVIEW_LOG = false
} JEflags;

typedef enum {
    JSIGINT = 2,
    JSIGKILL = 9,
    JSIGTERM = 15
} JSysSignal;


int CreateContext(JWindowSettings *settings, JDisplayContent *content, int ChromiumLogs ,bool ErrorS);
void DestroyContext(int pid,int debug, int signal);
void JwebviewTerminate(int pid);
#ifdef __cplusplus
}
#endif

#endif
