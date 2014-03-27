// strtok_for_string_C++.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include <iostream>
#include <string>
#include <vector>
#include <iterator>

#define tok
#undef tok

std::vector<std::string> strtok(const std::string , const std::string );

typedef std::string T_str;
typedef std::vector<T_str> T_vec;

int split_str_to_vec(const T_str , const T_str, T_vec & ); 

int main()
{
	std::string s(",Hello  world,!!!");
	std::string d (" ,.");
	std::vector<std::string> v;
#ifdef tok
	v = strtok (s, d);
#else
	split_str_to_vec (s, d, v);
#endif
	std::copy(v.begin(), v.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
	std::system ("pause");
	return 0;
}

std::vector<std::string> strtok(const std::string s, const std::string DELIM)
{
	std::vector<std::string> v;
	size_t l, r;

	for ( l = s.find_first_not_of(DELIM), r = s.find_first_of(DELIM, l) ; 
		l != std::string::npos ; l = s.find_first_not_of(DELIM, r), r = s.find_first_of(DELIM, l) )
		v.push_back(s.substr(l, r - l));
	return v;
}

int split_str_to_vec(const T_str s, const T_str DELIM, T_vec &v)
{
	size_t l, r;

	for ( l = s.find_first_not_of(DELIM), r = s.find_first_of(DELIM, l) ; 
		l != std::string::npos ; l = s.find_first_not_of(DELIM, r), r = s.find_first_of(DELIM, l) )
		v.push_back(s.substr(l, r - l));
	return v.size();
}


/*#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
 
int split_string_to_vector(const std::string & str, std::vector<std::string> & vec, const char sep){
        std::istringstream ist(str);
        std::string tmp;
        
        vec.clear();
        while ( std::getline(ist, tmp, sep) )
                vec.push_back(tmp);
        
        return vec.size();
}
 
 
int main(){
    const char SEP = '|';
        std::string str;
        std::vector<std::string> vec;
 
    while ( std::cout << "String: " && std::getline(std::cin, str) && ! str.empty() ){
                std::cout << split_string_to_vector(str, vec, SEP) << " tokens:" << std::endl;
                std::copy(vec.begin(), vec.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
        }
 
    return 0;
}



char* strtok (const char *s, const char *DELIM)
{
   static char *start, *end, *last;
   char *p;
   short f;
   
   if ( s )
   {
      start = s;
      for ( end = start ; *end ; ++end ) ;
   }
   else
   {
      start = last;
      *start = *DELIM;
   }
   
   while ( start != end )
   {
      for ( p = DELIM, f = 0 ; *p && !f ; ++p  )
         if ( *start == *p )
            f = 1;
      if ( !f ) 
         break;
      else
         ++start;         
   }
   
   for ( last = start ; last != end ; ++last )
   {
      for ( p = DELIM, f = 0 ; *p && !f ; ++p )
         if ( *last == *p )
            f = 1;
      if ( f ) 
         break;
   }
   
   if ( last == start )
      return NULL;
   else   
   {
      *last = '\0';
      return start;
   }
}      

*/


