#   Jeb Webview Tutorial

jebs Webview is a small launcher which uses the Chromium browser to render HTML files and URL files with minimal syntax.

---

## Webview Functions

```
//Version 2.0
int CreateContext(JWindowSettings *settings, JDisplayContent *content, int ChromiumLogs ,bool ErrorS);
void DestroyContext(int pid, int signal);
void JwebviewTerminate(int pid);
//Version 2.5
int CreateContext(JWindowSettings *settings, JDisplayContent *content);
void DestroyContext(int pid, int signal);
void JwebviewTerminate(int pid);
```

---

## Webview Window Flags

```
    ADDRESSBAR
    FULLSCREEN
    INCOGNITO
    KIOSKMODE
    ENABLE_GPU
    CHROMIUM_LOGS
    DEBUG
    JEB_LOG
    NO_ADDRESSBAR
    NO_FULLSCREEN
    NO_INCOGNITO
    NO_KIOSKMODE
    DISABLE_GPU
    NO_CHROMIUM_LOGS 
    NO_DEBUG
    NO_WEBVIEW_LOG
```

---

## Examples

### Render URL

```
#include "webview.h" 

int main(void) { 
    JWindowSettings settings = { 
        .WindowSize = {800,600}, 
        .Zoom = 100, 
        .AddressBar = 1 
    }; 
    JDisplayContent content = { 
        .Ctype = URL, 
        .buffer = "https://www.youtube.com" 
    }; 
    int pid = CreateContext(&settings,&content); 
    JwebviewTerminate(pid); 
    return 0; 
}
```

---

### Render HTML

```
#include "webview.h" 

int main(void) { 
    JWindowSettings settings = { 
        .WindowSize = {800,600}, 
        .Zoom = 100, 
        .AddressBar = 1 
    }; 
    JDisplayContent content = { 
        .Ctype = DOCUMENT, 
        .buffer = "test.html" 
    }; 
    int pid = CreateContext(&settings,&content); 
    JwebviewTerminate(pid); 
    return 0; 
}
```

---

## Supported Platforms

* Linux

---

## Compiling

```bash
gcc -DJVERSION_2_X target.c -lwebview -o target
```

---

## Versions
- 1.0 Release
- 2.0 New API more safety & control
- 2.5 more minimalism to CreateContext + new flags introduced
