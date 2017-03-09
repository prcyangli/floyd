#include <stdio.h>
#include <iostream>
#include <string>

#include "floyd_client.h"

using namespace std;

//struct option const long_options[] = {
//  {"servers", required_argument, NULL, 's'},
//  {NULL, 0, NULL, 0}, };

//const char* short_options = "s:";

int main(int argc, char* argv[]) {
  floyd::client::Option option;

  option.ParseFromArgs(argc, argv);

  floyd::client::Cluster cluster(option);

  int cnt = 1000;
  if (argc == 4) {
    char *end;
    cnt = strtol(argv[3], &end, 10);
  }
  printf ("cnt=%d\n", cnt);
  for (int i = 0; i < cnt; i++) {
    printf ("\n=====Test Write==========\n");

    std::string key = "test_key" + std::to_string(i);
    std::string value = "test_value" + std::to_string(i);

    pink::Status result = cluster.Write(key, value);
    if (result.ok()) {
      printf ("Write ok\n");
    } else {
      printf ("Write failed, %s\n", result.ToString().c_str());
    }

    printf ("\n=====Test Read==========\n");

    result = cluster.Read(key, &value);
    if (result.ok()) {
      printf ("read ok, value is %s\n", value.c_str());
    } else {
      printf ("Read failed, %s\n", result.ToString().c_str());
    }
  }

  cout << "success" << endl;
  return 0;
}