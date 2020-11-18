#ifndef HASP_DISPATCH_H
#define HASP_DISPATCH_H

#include "ArduinoJson.h"

#define LOG_CMND_CTR "CMND: "

bool is_true(const char * s);

void dispatchSetup(void);
void dispatchLoop(void);

// void dispatchCommand(const char * topic, const char * payload); // intenal
void dispatchConfig(const char * topic, const char * payload);
void dispatchTopicPayload(const char * topic, const char * payload);
void dispatchTextLine(const char * cmnd);

// void dispatchParseJson(char * strPayload);
// void dispatchParseJsonl(char * strPayload);
void dispatchParseJsonl(Stream & stream);

void dispatchPage(const char * page);
void dispatchPageNext();
void dispatchPagePrev();

void dispatchClearPage(const char * page);
void dispatchDim(const char * level);
void dispatchBacklight(const char * payload);

void dispatchWebUpdate(const char * espOtaUrl);
void dispatch_output_idle_state(const char * state);
void dispatchReboot(bool saveConfig);
void dispatch_output_statusupdate(void);

void dispatch_button(uint8_t id, const char * event);

void dispatch_send_object_event(uint8_t pageid, uint8_t objid, uint8_t eventid);
void dispatch_send_group_event(uint8_t groupid, uint8_t eventid, bool update_hasp);
bool dispatch_get_event_state(uint8_t eventid);

void IRAM_ATTR dispatch_send_obj_attribute_str(uint8_t pageid, uint8_t btnid, const char * attribute,
                                               const char * data);

struct haspCommand_t
{
    void (*func)(const char *);
    const char * p_cmdstr;
};

#endif