#include <iostream>
#include <cstdlib>

bool isInterleaved(char *s1, char *s2, char *s3) {
  if (!(*s1 || *s2 || *s3)) {
    return true;
  }
  else if (*s3 == '\0') {
    return false;
  }
  else {
    return ((*s1 == *s3 && isInterleaved(s1+1, s2, s3+1)) || (*s2 == *s3 && isInterleaved(s1, s2+1, s3+1)));
  }
}

void checkinterleaving(char *s1, char *s2, char *s3) {
  if (isInterleaved(s1, s2, s3)) {
    std::cout << "True\n";
  }
  else {
    std::cout << "False\n";
  }
}


int main() {
  char s1[] = "aabcc";
  char s2[] = "bbdcca";
  char s3[] = "aabbdcbccac";
  checkinterleaving(s1,s2,s3);
  checkinterleaving("XXY", "XXZ", "XXZXXXY");
  checkinterleaving("XY" ,"WZ" ,"WZXY");     
  checkinterleaving("XY", "X", "XXY");       
  checkinterleaving("YX", "X", "XXY");       
  checkinterleaving("XXY", "XXZ", "XXXXZY"); 
}
