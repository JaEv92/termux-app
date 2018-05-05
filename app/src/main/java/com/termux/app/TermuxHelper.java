package com.termux.app;

final class TermuxHelper {
    static {
        System.loadLibrary("termux-helper");
    }

    // Get owner of file/directory
    public static native int getFileUID(String path);

    // Get user id of current process
    public static native int getAppUID();
}
