#include <node.h>
#include <v8.h>

#include <wiringPi.h>

using namespace v8;

#define DECLARE(name) \
  static Handle<Value> name(const Arguments& args)
#define IMPLEMENT(name) \
  Handle<Value> wpi::name(const Arguments& args)
#define EXPORT(name)  \
  target->Set(String::NewSymbol("name"), \
  FunctionTemplate::New(wpi::name)->GetFunction())

namespace wpi {
  DECLARE(wiringPiSetup);
  DECLARE(pinMode);
  DECLARE(digitalWrite);
}

IMPLEMENT(wiringPiSetup) {
  HandleScope scope;
  int res;

  if (args.Length() != 0) {
    ThrowException(Exception::TypeError(
      String::New("Wrong number of arguments.")));
    return scope.Close(Undefined());
  }

  res = ::wiringPiSetup()

  return scope.Close(Int32::New(res));
}

IMPLEMENT(pinMode) {
  HandleScope scope;
  int res;

  if (args.Length() != 2) {
    ThrowException(Exception::TypeError(
      String::New("Wrong number of arguments.")));
    return scope.Close(Undefined());
  }

  if (!args[0]->IsNumber() || !args[1]->IsNumber()) {
    ThrowException(Exception::TypeError(
      String::New("Incorrect argument types. Numbers expected.")));
    return scope.Close(Undefined());
  }

  res = ::pinMode(args[0]->NumberValue(), args[1]->NumberValue());

  return scope.Close(Int32::New(res));
}

IMPLEMENT(digitalWrite) {
  HandleScope scope;
  int res;

  if (args.Length() != 2) {
    ThrowException(Exception::TypeError(
      String::New("Wrong number of arguments.")));
    return scope.Close(Undefined());
  }

  if (!args[0]->IsNumber() || !args[1]->IsNumber()) {
    ThrowException(Exception::TypeError(
      String::New("Incorrect argument types. Numbers expected.")));
    return scope.Close(Undefined());
  }

  res = ::digitalWrite(args[0]->NumberValue(), args[1]->NumberValue());

  return scope.Close(Int32::New(res));
}

void init(Handle<Object> target) {
  EXPORT(wiringPiSetup);
  EXPORT(pinMode);
  EXPORT(digitalWrite);
}
NODE_MODULE(wiringPi, init)
