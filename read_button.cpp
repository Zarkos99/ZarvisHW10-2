#include <iostream>         // for the input/output
#include <stdlib.h>         // for the getenv call
#include <sys/sysinfo.h>    // for the system uptime call
#include <cgicc/Cgicc.h>    // the cgicc headers
#include <cgicc/CgiDefs.h>
#include <cgicc/HTTPHTMLHeader.h>
#include <cgicc/HTMLClasses.h>
#include "GPIO.h"
using namespace exploringBB;
using namespace std;
using namespace cgicc;

int main(){
   Cgicc form;                      // the CGI form object
   string status;                      // the Set LED command
   GPIO inGPIO(46);
   inGPIO.setDirection(INPUT);

   // get the state of the form that was submitted - script calls itself
   bool isStatus = form.queryCheckbox("status");
   form_iterator it = form.getElement("status");  // the button command
   if (it == form.getElements().end() || it->getValue()==""){
      //status = "off";                     // if it is invalid use "off"
   }
   else { status = it->getValue(); }      // otherwise use submitted value
   char *value = getenv("REMOTE_ADDR");    // The remote IP address
 
   // generate the form but use states that are set in the submitted form
   cout << HTTPHTMLHeader() << endl;       // Generate the HTML form
   cout << html() << head() << title("Button Example") << head() << endl;
   cout << body() << h1("CPE 422 Reading a Pushbutton as a Digital Input") << endl;
   cout << h2("Reading a Pushbutton on gpio46 via a Web Browser") << endl;
   cout << "<form action=\"/cgi-bin/read_button.cgi\" method=\"POST\">\n";
   cout << "<div><input type=\"submit\" name=\"status\" value=\"Read Button\"";
   cout << "<br/>" << h2("Pushbutton State:") << endl;
   cout << "</div></form>";
 
   // process the form data to change the LED state
   cout << "<h2>Button is " << (inGPIO.getValue()==0?"Pressed </h2>":"Not Pressed</h2>") << endl;              // turn on
   cout << body() << html();
   return 0;
}
