#include <string>

void setup()
{
   while(!Serial);
   
   std::string s = "Hello STL";
   Serial.println(s.c_str());

}

void loop()
{   
}
