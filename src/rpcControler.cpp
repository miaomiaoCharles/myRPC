#include "rpcControler.hpp"

Controler::Controler(){
    isError = false;
    errorMessge = "";
}

void Controler::Reset(){
    isError = false;
    errorMessge = "";
}

bool Controler::Failed() const{
    return isError;
}

string Controler::ErrorText() const{
    return errorMessge;
}

void Controler::SetFailed(const string& reason){
    errorMessge = reason;
    isError = true;
}