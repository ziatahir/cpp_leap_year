bool leapYear(int y){
   bool isLeapYear = false;
   if (y % 4 == 0) {
      if (y % 100 == 0) {
         if (y % 400 == 0) {
            isLeapYear = true;
         }
      } 
      else isLeapYear = true;
   }
   return isLeapYear;
}
