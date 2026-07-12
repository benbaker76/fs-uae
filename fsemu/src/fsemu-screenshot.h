#ifndef FSEMU_SCREENSHOT_H_
#define FSEMU_SCREENSHOT_H_

#include <stdbool.h>

#include "fsemu-video.h"

#ifdef __cplusplus
extern "C" {
#endif

void fsemu_screenshot_init(void);

const char *fsemu_screenshot_dir(void);

void fsemu_screenshot_capture(void);
bool fsemu_screenshot_should_capture(void);
void fsemu_screenshot_confirm_captured(void);

// Maybe
// int fsemu_screenshot_crop(int *x, int *y, int *w, int *h):
// void fsemu_screenshot_set_crop(int x, int y, int w, int h);

const char *fsemu_screenshot_path(void);
const char *fsemu_screenshot_path_for_type(const char *type);

void fsemu_screenshot_capture_video_frame(fsemu_video_frame_t *frame);

// SWOS gdb harness: retain a copy of the last composited frame, and capture the
// current (halted) frame synchronously to a PNG from that snapshot — so a
// screenshot can be taken while the CPU is halted for gdb without resuming the
// emulator to let the video thread pick up the deferred capture flag.
void fsemu_screenshot_store_last_frame(fsemu_video_frame_t *frame);
void fsemu_screenshot_capture_now(void);

#ifdef FSEMU_INTERNAL

// ----------------------------------------------------------------------------
// Logging
// ----------------------------------------------------------------------------

extern int fsemu_screenshot_log_level;

#define fsemu_screenshot_log(format, ...) \
    FSEMU_LOG(screenshot, "[FSE] [SHT]", format, ##__VA_ARGS__)

#define fsemu_screenshot_log_debug(format, ...) \
    FSEMU_LOG_DEBUG(screenshot, "[FSE] [SHT]", format, ##__VA_ARGS__)

#define fsemu_screenshot_log_error(format, ...) \
    FSEMU_LOG_ERROR(screenshot, "[FSE] [SHT]", format, ##__VA_ARGS__)

#define fsemu_screenshot_log_info(format, ...) \
    FSEMU_LOG_INFO(screenshot, "[FSE] [SHT]", format, ##__VA_ARGS__)

#define fsemu_screenshot_log_trace(format, ...) \
    FSEMU_LOG_TRACE(screenshot, "[FSE] [SHT]", format, ##__VA_ARGS__)

#define fsemu_screenshot_log_warning(format, ...) \
    FSEMU_LOG_WARNING(screenshot, "[FSE] [SHT]", format, ##__VA_ARGS__)

// ----------------------------------------------------------------------------

#endif  // FSEMU_INTERNAL

#ifdef __cplusplus
}
#endif

#endif  // FSEMU_SCREENSHOT_H_
