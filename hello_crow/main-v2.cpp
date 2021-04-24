#include "crow_all.h"
using namespace std;
using namespace crow;

int main(int argc, char* argv[]) {
  crow::SimpleApp app;

  CROW_ROUTE(app, "/")
    ([](const request &req, response &res){
      ifstream in("../public/index.html", ifstream::in);
      if(in){
        ostringstream contents;
        contents << in.rdbuf();
        in.close();
        res.write(contents.str());
      } else {
        res.write("Not found! Awww... Don't be sad, it's just a 404 Error!");
      }
      res.end();
    });

char* port = getenv("PORT");
uint16_t iPort = static_cast<uint16_t>(port != NULL? stoi(port): 18080);
cout << "PORT = " << iPort << "\n";
app.port(iPort).multithreaded().run();
}
