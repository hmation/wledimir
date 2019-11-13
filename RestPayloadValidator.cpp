#include "RestPayloadValidator.h"

#define ERR_CODE 400
#define SUC_CODE 200

#define JSON_LED "led"
#define JSON_VALUE "value"
#define JSON_EFFECT "effect"

RestPayloadValidator::RestPayloadValidator()
{
}

struct RestPayloadValidationResult RestPayloadValidator::validate(StaticJsonDocument<150> json, DeserializationError error)
{

    struct RestPayloadValidationResult result;
    result.faulty = false;
    result.message = "OK.";
    result.httpErrorCode = SUC_CODE;

    if (error)
    {
        result.faulty = true;
        result.message = "Cannot parse message.";
        result.httpErrorCode = ERR_CODE;
        return result;
    }

    if (json[JSON_LED] != 1 && json[JSON_LED] != 2)
    {
        result.faulty = true;
        result.message = "The led number has to be either 1 or 2.";
        result.httpErrorCode = ERR_CODE;
        return result;
    }

    if (json[JSON_VALUE] < 0 || json[JSON_VALUE] > 100)
    {
        result.faulty = true;
        result.message = "The value has to be in range <0,100>.";
        result.httpErrorCode = ERR_CODE;
        return result;
    }

    return result;
}
