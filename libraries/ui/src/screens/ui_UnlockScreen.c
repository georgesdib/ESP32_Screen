// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.0
// LVGL version: 8.3.6
// Project name: SquareLine_Project

#include "../ui.h"

void ui_UnlockScreen_screen_init(void)
{
ui_UnlockScreen = lv_obj_create(NULL);
lv_obj_clear_flag( ui_UnlockScreen, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_UnlockScreen, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_UnlockScreen, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Keyboard = lv_keyboard_create(ui_UnlockScreen);
lv_keyboard_set_mode(ui_Keyboard,LV_KEYBOARD_MODE_NUMBER);
lv_obj_set_width( ui_Keyboard, 352);
lv_obj_set_height( ui_Keyboard, 186);
lv_obj_set_x( ui_Keyboard, -3 );
lv_obj_set_y( ui_Keyboard, 30 );
lv_obj_set_align( ui_Keyboard, LV_ALIGN_CENTER );

lv_obj_set_style_bg_color(ui_Keyboard, lv_color_hex(0xFFFFFF), LV_PART_ITEMS | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Keyboard, 255, LV_PART_ITEMS| LV_STATE_DEFAULT);

ui_TextArea = lv_textarea_create(ui_UnlockScreen);
lv_obj_set_width( ui_TextArea, 205);
lv_obj_set_height( ui_TextArea, LV_SIZE_CONTENT);   /// 43
lv_obj_set_x( ui_TextArea, -11 );
lv_obj_set_y( ui_TextArea, -107 );
lv_obj_set_align( ui_TextArea, LV_ALIGN_CENTER );
lv_textarea_set_max_length(ui_TextArea,10);
lv_textarea_set_placeholder_text(ui_TextArea,"PIN Code");
lv_textarea_set_one_line(ui_TextArea,true);

lv_obj_add_event_cb(ui_TextArea, ui_event_TextArea, LV_EVENT_ALL, NULL);

}
