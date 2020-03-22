#include <node.h>
#include"func.h"
 

#pragma comment(lib, "Dll1.lib")

using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::Object;
using v8::String;
using v8::NewStringType;
using v8::Value;
 
void NodeGetSteamId(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();
    char steamid[256];
    char steam64id[256];
    strcpy(steamid, GetSteamId());
    strcpy(steam64id, GetSteamLink(steamid));

    if (steamid == nullptr) {
        args.GetReturnValue().Set(String::NewFromUtf8(
            isolate, "0", NewStringType::kNormal).ToLocalChecked());
    }
    else {
        args.GetReturnValue().Set(String::NewFromUtf8(
            isolate, steamid, NewStringType::kNormal).ToLocalChecked());
    }
}

void NodeGetSteam64Id(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();
    char steamid[256];
    char steam64id[256];
    char* result = GetSteamId();
    if (result == nullptr || !result) {
        args.GetReturnValue().Set(String::NewFromUtf8(
            isolate, "0", NewStringType::kNormal).ToLocalChecked());
    }
    else {
        strcpy(steamid, result);
        strcpy(steam64id, GetSteamLink(steamid));
        args.GetReturnValue().Set(String::NewFromUtf8(
            isolate, steam64id, NewStringType::kNormal).ToLocalChecked());
    }
}
 
void init(Local<Object> exports) {
  NODE_SET_METHOD(exports, "NodeGetSteamId", NodeGetSteamId);
  NODE_SET_METHOD(exports, "NodeGetSteam64Id", NodeGetSteam64Id);
}
 
NODE_MODULE(FaceRecognition, init)
