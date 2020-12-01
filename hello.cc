#include <iostream>
#include <napi.h>

namespace maps {

Napi::Value HelloMethod(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    return Napi::String::New(env, "Hello World");
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
    exports.Set(Napi::String::New(env, "hello"),
                Napi::Function::New(env, HelloMethod));
    return exports;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, Init)

} // End namespace prime
