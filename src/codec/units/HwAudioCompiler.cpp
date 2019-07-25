/*
* Copyright (c) 2018-present, lmyooyo@gmail.com.
*
* This source code is licensed under the GPL license found in the
* LICENSE file in the root directory of this source tree.
*/

#include "../include/HwAudioCompiler.h"
#include "HwBuffer.h"
#include "HwModelProvider.h"

HwAudioCompiler::HwAudioCompiler() : Unit() {
    name = __FUNCTION__;
    registerEvent(EVENT_COMMON_PREPARE,
                  reinterpret_cast<EventFunc>(&HwAudioCompiler::eventPrepare));
    registerEvent(EVENT_MICROPHONE_OUT_SAMPLES,
                  reinterpret_cast<EventFunc>(&HwAudioCompiler::eventReceiveData));
}

HwAudioCompiler::~HwAudioCompiler() {

}

bool HwAudioCompiler::eventRelease(Message *msg) {
    if (muxer) {
        delete muxer;
        muxer = nullptr;
    }
    return true;
}

bool HwAudioCompiler::eventPrepare(Message *msg) {
    Object *f = static_cast<HwModelProvider *>(getModelProvider())->getObject("_format");
    HwSampleFormat *format = reinterpret_cast<HwSampleFormat *>(f);
    string path = static_cast<HwModelProvider *>(getModelProvider())->getString("_path");
    muxer = WAVRawMuxer::build(path, *format);
    return true;
}

bool HwAudioCompiler::eventReceiveData(Message *msg) {
    HwBuffer *buf = dynamic_cast<HwBuffer *>(msg->obj);
    if (buf && muxer) {
        muxer->write(buf);
    }
    return true;
}