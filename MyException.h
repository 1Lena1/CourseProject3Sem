#pragma once

class MyException {
protected:
    int code;
public:
    explicit MyException(int code = 0) { this->code = code; }
    virtual void ErrorText(){};
};
