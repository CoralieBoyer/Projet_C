#include <stdio.h>
#include <curl/curl.h>
#include <stdlib.h>
#include <string.h>

int function_pt(void *ptr, size_t size, size_t nmemb, void *stream){
  char **response_ptr =  (char**)stream;
*response_ptr = strndup(ptr, (size_t)(size *nmemb));

}

void recoverDate(){
  CURL *curl;
  CURLcode res;

  char *response = calloc(1,sizeof(char));
  curl_global_init(CURL_GLOBAL_DEFAULT);


  curl = curl_easy_init();
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, "http://worldclockapi.com/api/jsonp/cet/now?callback=mycallback");

    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, function_pt);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

    res = curl_easy_perform(curl);

/*    if(res != CURLE_OK) //cas d'erreur
      fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));*/

    curl_easy_cleanup(curl);
  }

  curl_global_cleanup();

  strncpy(date,response+41,16);
  date[16] = '\0';
}

/*
int main(int argc,char**argv){
  recoverDate();
  printf("%s",date);
   return 0;
}
*/
