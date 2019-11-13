#include <Arduino.h>
#include <ArduinoJson.h>

class RestPayloadValidator
{
public:
    RestPayloadValidator();

    struct RestPayloadValidationResult validate(StaticJsonDocument<150> StaticJsonDocument, DeserializationError error);
};

struct RestPayloadValidationResult
{
    boolean faulty = false;
    String message;
    short httpErrorCode;
};
