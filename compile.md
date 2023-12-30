```
emcc -o game.html src/*.c src/components/*.c -Os -Wall /home/haro/raylib/src/web/libraylib.a -I. -I/home/haro/raylib/src/ -L. -L/home/haro/raylib/src/web/librarylib.a -s USE_GLFW=3 -sGL_ENABLE_GET_PROC_ADDRESS -s ASYNCIFY --shell-file /home/haro/raylib/src/shell.html -DPLATFORM_WEB --preload-file assets --preload-file audio -s TOTAL_MEMORY=2147483648 -s ASSERTIONS=1 -s TOTAL_STACK=2097152
```
