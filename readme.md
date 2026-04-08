# Webview Tutorial

Webview is a small library which uses the Chromium browser to render HTML files and URL files with minimal syntax.

---

## Webview Functions

```diff
void WindowSizeInit(JWindowSize *sz, int width, int height);
+ int WindowSettingsInit(JWindowSettings *settings, int addressbar, int fullscreen, int incognito, int kioskmode);
- int DisplayContent(JDisplayContent *content, int Ctype, char* buffer);
void CreateContext(JWindowSettings *settings, JDisplayContent *content, bool LOG);
```

---

## Webview Window Flags

```diff
+ ADDRESSBAR = 1,
+ FULLSCREEN = 1,
+ INCOGNITO = 1,
+ KIOSKMODE = 1,
- NO_ADDRESSBAR = 0,
- NO_FULLSCREEN = 0,
- NO_INCOGNITO = 0,
- NO_KIOSKMODE = 0,
- NO_JEB_LOG = false
```

---

## Examples

### Render URL

```diff
#include <webview.h>
#include <stdio.h>

int main() {
    JWindowSettings settings;
    JDisplayContent content;

    WindowSizeInit(&settings.WindowSize, 800, 600); // set window size for Chromium
-    WindowSettingsInit(&settings, NO_ADDRESSBAR, NO_FULLSCREEN, INCOGNITO, NO_KIOSKMODE); // available browser modes
+    WindowSettingsInit(&settings, NO_ADDRESSBAR, NO_FULLSCREEN, INCOGNITO, NO_KIOSKMODE); // available browser modes (green = enabled)
-    DisplayContent(&content, URL, "https://www.youtube.com");
+    DisplayContent(&content, URL, "https://www.youtube.com"); // red = URL to render
    CreateContext(&settings, &content, NO_WEBVIEW_LOG); // Create the browser window and display content

    return 0;
}
```

---

### Render HTML

```diff
#include <webview.h>
#include <stdio.h>

int main() {
    JWindowSettings settings;
    JDisplayContent content;

    WindowSizeInit(&settings.WindowSize, 800, 600);
-    WindowSettingsInit(&settings, NO_ADDRESSBAR, NO_FULLSCREEN, INCOGNITO, NO_KIOSKMODE);
+    WindowSettingsInit(&settings, NO_ADDRESSBAR, NO_FULLSCREEN, INCOGNITO, NO_KIOSKMODE); // green = enabled, red = disabled
-    DisplayContent(&content, DOCUMENT, "path/to/local/file.html");
+    DisplayContent(&content, DOCUMENT, "path/to/local/file.html"); // local HTML file
    CreateContext(&settings, &content, NO_WEBVIEW_LOG);

    return 0;
}
```

---

## Supported Platforms

* Linux

---

## Compiling

```bash
gcc target.c -lwebview -o target
```
