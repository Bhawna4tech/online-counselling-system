# online-counselling-system
Used a structure to bind all the information that a student holds . 
In this project ,the main purpose is to categorize whole data according to delhi and outside delhi and then in each state wise category , we divided data in SC , ST , GENERAL AND OBC category . 
in the function , convert_d_od() , we read a structure ( a particular record of a student ) , then we check whether the state of that person = DELHI or not . if it is DELHI , we create a new file named DELHI.TXT and put that record in it . same goes for outside delhi . 
in the function , convert_d_cat() , we read a record and then we compared category of each record to SC , ST , OBC , and general and then we put that record into respective files . 
same goes for convert_od_cat();
now , important function that we have made is sorting () . we have used an important feature of C++ , STL (standard template library ) . 
here , we used vector ( because we don’t exactly know how many records will be there . Here , we read a record and then push_back that record at the end of vector . now we used std::sort function , to sort all the records according to the rank in the file DATA.TXT .
