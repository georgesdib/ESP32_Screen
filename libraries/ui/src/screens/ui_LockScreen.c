// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.0
// LVGL version: 8.3.6
// Project name: SquareLine_Project

#include "../ui.h"

void ui_LockScreen_screen_init(void)
{
    ui_LockScreen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_LockScreen, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_bg_color(ui_LockScreen, lv_color_hex(0x030000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_LockScreen, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ArmHomeButton = lv_btn_create(ui_LockScreen);
    lv_obj_set_width(ui_ArmHomeButton, 100);
    lv_obj_set_height(ui_ArmHomeButton, 50);
    lv_obj_set_x(ui_ArmHomeButton, 130);
    lv_obj_set_y(ui_ArmHomeButton, -10);
    lv_obj_set_align(ui_ArmHomeButton, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ArmHomeButton, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
    lv_obj_clear_flag(ui_ArmHomeButton, LV_OBJ_FLAG_SCROLLABLE);    /// Flags

    ui_ArmNightButton = lv_btn_create(ui_LockScreen);
    lv_obj_set_width(ui_ArmNightButton, 100);
    lv_obj_set_height(ui_ArmNightButton, 50);
    lv_obj_set_x(ui_ArmNightButton, -5);
    lv_obj_set_y(ui_ArmNightButton, -10);
    lv_obj_set_align(ui_ArmNightButton, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ArmNightButton, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
    lv_obj_clear_flag(ui_ArmNightButton, LV_OBJ_FLAG_SCROLLABLE);    /// Flags

    ui_ArmAwayButton = lv_btn_create(ui_LockScreen);
    lv_obj_set_width(ui_ArmAwayButton, 100);
    lv_obj_set_height(ui_ArmAwayButton, 50);
    lv_obj_set_x(ui_ArmAwayButton, -136);
    lv_obj_set_y(ui_ArmAwayButton, -10);
    lv_obj_set_align(ui_ArmAwayButton, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ArmAwayButton, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
    lv_obj_clear_flag(ui_ArmAwayButton, LV_OBJ_FLAG_SCROLLABLE);    /// Flags

    ui_ArmAwayLabel = lv_label_create(ui_LockScreen);
    lv_obj_set_width(ui_ArmAwayLabel, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_ArmAwayLabel, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_ArmAwayLabel, -136);
    lv_obj_set_y(ui_ArmAwayLabel, -10);
    lv_obj_set_align(ui_ArmAwayLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_ArmAwayLabel, "Arm Away");

    ui_ArmNightLabel = lv_label_create(ui_LockScreen);
    lv_obj_set_width(ui_ArmNightLabel, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_ArmNightLabel, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_ArmNightLabel, -10);
    lv_obj_set_y(ui_ArmNightLabel, -10);
    lv_obj_set_align(ui_ArmNightLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_ArmNightLabel, "Arm Night");

    ui_ArmHomeLabel = lv_label_create(ui_LockScreen);
    lv_obj_set_width(ui_ArmHomeLabel, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_ArmHomeLabel, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_ArmHomeLabel, 128);
    lv_obj_set_y(ui_ArmHomeLabel, -10);
    lv_obj_set_align(ui_ArmHomeLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_ArmHomeLabel, "Arm Home");

    ui_StatusLabel = lv_label_create(ui_LockScreen);
    lv_obj_set_width(ui_StatusLabel, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_StatusLabel, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_StatusLabel, -21);
    lv_obj_set_y(ui_StatusLabel, -102);
    lv_obj_set_align(ui_StatusLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_StatusLabel, "");
    lv_obj_set_style_text_color(ui_StatusLabel, lv_color_hex(0xE62323), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_StatusLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_ArmHomeButton, ui_event_ArmHomeButton, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ArmNightButton, ui_event_ArmNightButton, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ArmAwayButton, ui_event_ArmAwayButton, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ArmHomeLabel, ui_event_ArmHomeLabel, LV_EVENT_ALL, NULL);
}
