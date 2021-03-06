# napi-hello-world
Just a *hello world* using NodeJS native API (n-api) for C++ plugins.

This project just compile this simple C++ NodeJS module to be consumed in Javascript land. 

```cpp
#include <iostream>
#include <napi.h>

namespace hello {

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

} // End hello namespace
```

> To run this example just do `npm install` and after that `npm start` to execute the `index.js` file.


## Invoking From JS

From JS you can invoke the `hello` native method like this: 

```js
const addon = require('./build/Release/hello.node');
console.log('hello: ', addon.hello())
```

If you need more information you can access [n-api documentation](https://github.com/nodejs/node-addon-api/tree/master/doc).
