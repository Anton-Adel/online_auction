#include <iostream>
#include <string>

using namespace std;
int index1, index2; //these variables are used in the function login to save the index of the seller or buyer
struct address {
	
	int House_number;
	string street;
	string city;
};
struct date{

	int day, month, year;
};
struct product{
	char seller_name[60];   // the seller must enter his name to save that this product is the product for this seller 
	int item_number;
	string category;
	float starting_bid_price;
	date the_start_date, the_end_date;
	string status;
	int quantity=0;
};
struct seller {
	char total_name[60];
	string  id;
	char telephone_number[30];
	string  E_mail;
	string pass_word;
	int pionts = 1;
	
};
struct buyer {
	char total_name[60];
	string  id;
	char telephone_number[30];
	string  E_mail;
	string pass_word;
	address buyer_address;
	int points = 1;
};
void e_mail(seller *sel); //this function is used in the function seller input to create the email of the seller
void e_mail(buyer *buy);   //this function is used in the function buyer input to create the email of the buyer
void seller_input(seller *sel);
void buyer_input(buyer *buy);
bool login(seller *sel, int size);
bool login(buyer *buy, int size);
void product_for_sel(product *prod, int size,seller *sel);
void feedback(seller *sel, int size);
void feedback(buyer *buy, int size);
void buy(product *pro_buy, product *prod, int size);
void month_best_sel(product *pro_buy, int rows, product *prod, int size);

int main(){
	int size;
	int sellers_numbers, buyers_numbers,number_of_products;
	cout << "Hello manager please enter the number of sellers and buyers \n";
	cout << "--------------------------------------------------------\n";
	cout << "The sellers number\n";
	cin >> sellers_numbers;
	cout << "The buyers number\n";
	cin >> buyers_numbers;
	cout << "The number of products for the list market\n";
	cin >> number_of_products;
	cout << "The number of products that can be selled in the month \n";   
	cin >> size;

	seller *seller_s = new seller[sellers_numbers]();
	buyer *buyer_s = new buyer[buyers_numbers]();
	product *product_sel = new product[number_of_products]();
	product *product_buy = new product[size];
	int check1 = 0, check2 = 0;
	bool done = true;
	do{
		int choice1=0, choice2=0;

		cout << "choose the number that you want to do \n";
		cout << "----------------------------------------------------\n";
		cout << "- 1. sign up                                       -\n";
		cout << "- 2.login                                          -\n";
		cout << "----------------------------------------------------\n";
		cin >> choice1;
		switch (choice1){
		case 1:
			cout << "choose your identification a \n";
			cout << "----------------------------------------------------\n";
			cout << "- 1. seller                                        -\n";
			cout << "- 2. buyer                                         -\n";
			cout << "----------------------------------------------------\n";
			cin >> choice2;
			switch (choice2){
			case 1:
				if (check1 < sellers_numbers){
					seller_input(&seller_s[check1]);
					check1++;
				}
				else
				{

					cout << " number of sellers is complite \n ";
				}

				break;

			case 2:
				if (check2 < buyers_numbers){
					buyer_input(&buyer_s[check2]);
					check2++;
				}
				else
				{

					cout << " number of buyers is complite \n ";
				}

				break;
			default:
				cout << "wrong choice \n";
			}
			break;
		case 2:
			cout << "choose your identification a \n";
			cout << "----------------------------------------------------\n";
			cout << "- 1. seller                                        -\n";
			cout << "- 2. buyer                                         -\n";
			cout << "----------------------------------------------------\n";
			cin >> choice2;
			switch (choice2){
			case 1:
				bool log_in;
				int seller_choice,feedback_member;
				log_in = login(seller_s, sellers_numbers);
				if (log_in == true){
					cout << "Hello seller \n";
					bool repeat = false;
					do{
						cout << "choose the number that you want to do \n";
						cout << "----------------------------------------------------\n";
						cout << "- 1. offer a product to sell it                    -\n";
						cout << "- 2.give feedback                                  -\n";
						cout << "- 3.show the best selling products                 -\n";
						cout << "- 4.quit                                           -\n";
						cout << "----------------------------------------------------\n";
						cin >> seller_choice;
						switch (seller_choice){
						case 1:
							product_for_sel(product_sel, number_of_products, &seller_s[index1]);
							break;
						case 2:
							cout << "who the feedback will be in \n";
							cout << "----------------------------------------------------\n";
							cout << "- 1. seller                                        -\n";
							cout << "- 2. buyer                                         -\n";
							cout << "----------------------------------------------------\n";
							cin >> feedback_member;
							switch (feedback_member){
							case 1:
								feedback(seller_s, sellers_numbers);
								break;
							case 2:
								feedback(buyer_s, buyers_numbers);
								break;
							}
							break;
						case 3:
							month_best_sel(product_buy, size, product_sel, number_of_products);
							break;
						case 4:
							repeat = true;
							break;
						default:
							cout << "invalid choice \n";
						}
					} while (repeat != true);

				}
				break;
			case 2:
				bool log_in2;
				int buyer_choice, feedback_member2;
				log_in2 = login(buyer_s, buyers_numbers);
				if (log_in2 == true){
					cout << "Hello buyer \n";
					bool repeat = false;
					do{
						cout << "choose the number that you want to do \n";
						cout << "----------------------------------------------------\n";
						cout << "- 1. buy a product                                 -\n";
						cout << "- 2.give feedback                                  -\n";
						cout << "- 3.show the best selling products                 -\n";
						cout << "- 4.quit                                           -\n";
						cout << "----------------------------------------------------\n";
						cin >> buyer_choice;
						switch (buyer_choice){
						case 1:
							bool fine;  // used for check
							do{
								fine = false;
								int pro = 0;
								if (pro < size){
									buy(&product_buy[pro], product_sel, number_of_products);
								}
								else{
									fine = true;             //"if The number of products that can be selled in the month completed 
								}                             // the last month is finished an a new month start with new products"
							} while (fine== true);
							break;
						case 2:
							cout << "who the feedback will be in \n";
							cout << "----------------------------------------------------\n";
							cout << "- 1. seller                                        -\n";
							cout << "- 2. buyer                                         -\n";
							cout << "----------------------------------------------------\n";
							cin >> feedback_member2;
							switch (feedback_member2){
							case 1:
								feedback(seller_s, sellers_numbers);
								break;
							case 2:
								feedback(buyer_s, buyers_numbers);
								break;
							}
							break;
						case 3:
							month_best_sel(product_buy, size, product_sel, number_of_products);
							break;
						case 4:
							repeat = true;
							break;
						default:
							cout << "invalid choice \n";

						}
					} while (repeat != true);
				}
			}
			break;
		}

		}while (done == true);

		
	delete[]seller_s;
	delete[]buyer_s;
	delete[]product_sel;
	delete[] product_buy;


	seller_s = NULL;
	buyer_s = NULL;
	product_sel = NULL;
	product_buy = NULL;
	return 0;
}
 void e_mail(seller *sel){

	bool valid = false;
	string name, id;
	string formal = "@seller.com";
	do{
		cout << "Please enter only your first name and id to create your e_mail\n";
		cin >> name >> id;
		if (id == (*sel).id){
			cout << "your E_mail is  \n";
			(*sel).E_mail = name + id + formal;
			cout << (*sel).E_mail << "\t\t" << "*please remember it* \n";
			valid = true;
		}
		else {
			cout << "your e_mail is invalid \n";
		}
	} while (valid != true);
}

void e_mail(buyer *buy){

	bool valid = false;
	string name, id;
	string formal = "@buyer.com";
	do{
		cout << "Please enter only your first name and id to create your e_mail\n";
		cin >> name >> id;
		if (id == (*buy).id){
			cout << "your E_mail is  \n";
			(*buy).E_mail = name + id + formal;
			cout << (*buy).E_mail << "\t\t" << "*please remember it* \n";
			valid = true;
		}
		else {
			cout << "your e_mail is invalid \n";
		}
	} while (valid != true);
}

void seller_input(seller *sel){

	cout << "\n please enter your details\n\n";
	cout << "enter your total name \n";
	cin.ignore();
	gets_s((*sel).total_name, 60);
	cout << "enter your id \n";
	cin >> (*sel).id;
	cout << "enter your telephne number \n";
	cin >> (*sel).telephone_number;
	e_mail(sel);
	cout << "enter your pass word \n";
	cin.ignore();
	
	getline(cin, (*sel).pass_word);
}

void buyer_input(buyer *buy){

	cout << "\n please enter your details\n\n";
	cout << "enter your total name \n";
	cin.ignore();
	gets_s((*buy).total_name, 60);
	cout << "enter your id \n";
	cin >> (*buy).id;
	cout << "enter your telephne number \n";
	cin >> (*buy).telephone_number;
	e_mail(buy);
	cout << "enter your pass word \n";
	cin.ignore();
	getline(cin, (*buy).pass_word);
	cout << "enter your address \n";
	cout << "enter your city \n";
	cin >> (*buy).buyer_address.city;
	cout << "enter your street \n";
	cin.ignore();
	getline(cin, (*buy).buyer_address.street);
	cout << "enter your house number \n";
	cin >> (*buy).buyer_address.House_number;
}

bool login(seller *sel, int size){
	string  email;
	string  password;
	int enter_value = -200;
	bool choice = false, choice2 = false;
	do{
		cout << "enter your e_mail and password \n";
		cout << "E_mail \n";
		cin.ignore();
		getline(cin, email);
		for (int i = 0; i < size; i++){
			if (sel[i].E_mail == email){
				choice = true;
				index1 = i;
				break;
			}
		}

		if (choice != true)
			cout << "the error in email \n";

		if (choice == true){
			choice = false;
			cout << " password \n";
			getline(cin, password);
			if (sel[index1].pass_word == password){
				cout << "done \n";
				choice = true;
			}
			if (choice != true)
				cout << "the error in password \n";
		}

		if (choice != true){
			cout << "\n if you want to login again press 1 else press 00\n";
			cin >> enter_value;
		}
		if (enter_value == 00)
			choice2 = true;
		else if (choice == true)
			choice2 = true;
		else
			choice2 = false;
	} while (choice2 != true);
	if (choice == true)
		return true;
	else
		return false;

}

bool login(buyer *buy, int size){
	string email;
	string password;
	int enter_value= -200;
	bool choice = false, choice2 = false;
	do{
		cout << "enter your e_mail and password \n";
		cout << " E_mail \n";
		cin.ignore();
		getline(cin, email);
		for (int i = 0; i < size; i++){
			if (buy[i].E_mail == email){
				choice = true;
				index2 = i;
				break;
			}
		}

		if (choice != true)
			cout << "the error in email \n";

		if (choice == true){
			choice = false;
			cout << " password \n";
			getline(cin, password);
			if (buy[index2].pass_word == password){
				cout << "done \n";
				choice = true;
			}
			if (choice != true)
				cout << "the error in password \n";
		}
		
		if (choice != true){
			cout << "\n if you want to login again press 1 else press 00\n";
			cin >> enter_value ;
		}
		if (enter_value == 00)
			choice2 = true;
		else if (choice == true)
			choice2 = true;
		else
			choice2 = false;
	} while (choice2 != true);
	if (choice == true)
		return true;
	else
		return false;

}

void product_for_sel(product *prod, int size, seller *sel){
	int item_number,choice;
		cout << "Hello sir please enter the amount of items \n";
		cin >> item_number;
		for (int i = 0; i < item_number; i++){
			cout << "please at first enter your name sir \n";
			cin.ignore();
			gets_s((*sel).total_name, 60);
			cout << "enter the item number \n";
			cin >> prod[i].item_number;
			cout << "enter the category \n";
			cin.ignore();   

			getline(cin, prod[i].category);
			cout << "enter the starting bid price \n";
			cin >> prod[i].starting_bid_price;
			cout << "enter the the start date of the auction process \n";
			cin >> prod[i].the_start_date.day >> prod[i].the_start_date.month >> prod[i].the_start_date.year;
			cout << "enter the the end date of the auction process \n";
			cin >> prod[i].the_end_date.day >> prod[i].the_end_date.month >> prod[i].the_end_date.year;
			bool done = true;
			do{
				cout << "choose the status of the item \n";
				cout << "----------------------------------------------------\n";
				cout << "- 1. available                                     -\n";
				cout << "- 2. sold                                          -\n";
				cout << "----------------------------------------------------\n";
				cin >> choice;
				switch (choice){
				case 1:
					prod[i].status = ("available");
					break;
				case 2:
					prod[i].status = ("sold");
					break;
				default:
					cout << "invalid choice\n";
					done = false;
				}

			} while (done != true);
			cout << "----------------------------------------------\n";
           }
		cout << "----------------------------------------------\n";
}

void feedback(seller *sel, int size){
	string id;
	int appreciation;
	char feedback[100];
	cout << "please sir enter the id of seller \n";
	cin >> id;
	cout << "what is your assessment for him (from 1 to 5) star \n";
	cin >> appreciation;
	if (appreciation >= 3 && appreciation <= 5){
		for (int i = 0; i < size; i++){
			if (sel[i].id == id)
				sel[i].pionts += 1;
		}
	}
	cout << "enter your feedback sir and when you enter new line your feedback will be finished  \n";
	cin.ignore();
	gets_s(feedback, 100);
}

void feedback(buyer *buy, int size){

	string id;
	int appreciation;
	char feedback[100];
	cout << "please sir enter the id of buyer \n";
	cin >> id;
	cout << "what is your assessment for him (from 1 to 5) star \n";
	cin >> appreciation;
	if (appreciation >= 3 && appreciation <= 5){
		for (int i = 0; i < size; i++){
			if (buy[i].id == id)
				buy[i].points += 1;
		}
	}
	cout << "enter your feedback sir and when you enter new line your feedback will be finished \n";
	cin.ignore();
	gets_s(feedback, 100);
}

void buy(product *pro_buy, product *prod, int size){
	int choice,choice2,item_number;
	float price=0,item_price=0;
	cout << "Hello if you want to search with category press 1 and press 2 with category and price \n";
	cin >> choice;
	bool found=false;
	string category;
	if (choice == 1){
		cout << "enter the category \n";
		cin.ignore();
		getline(cin, category);
		cout << "--------------------------------------------------------\n";
		cout << "-category   -    price   -    item number                     \n";
		for (int i = 0; i < size; i++){
			if (prod[i].category == category)
			if (prod[i].status == "available") {
				cout << "-" << prod[i].category << "   -   " << prod[i].starting_bid_price << "   -   " << prod[i].item_number << "-" << "\n";
				found = true;
			}
		}

		cout << "---------------------------------------------------------\n";
		if (found == false)
			cout << "there is no item like that \n";
		if (found == true){
			cout << "if you want buy this item with his price press 1 else if you want to enter new price press 2 \n";
			cin >> choice2;
			if (choice2 == 1){
				cout << "enter the item number please to send the request\n";
				cin >> item_number;
				found = false;
				for (int i = 0; i < size; i++){
					if (prod[i].item_number == item_number)
					if (prod[i].status == "available") {
						cout << "the product is yours now \n";
						prod[i].status = "sold";
						found = true;
						(*pro_buy).category = prod[i].category;
						(*pro_buy).quantity++;
					}
				}
				if (found == false)
					cout << "there is no item number like that \n";
			}

			else{
				cout << "enter the item number and price please to send the request \n";
				cin >> item_number>>price;
				found = false;
				for (int i = 0; i < size; i++){
					if (prod[i].item_number == item_number&&(prod[i].starting_bid_price>=price&&(prod[i].starting_bid_price-prod[i].starting_bid_price*0.1)<=price))
					if (prod[i].status == "available") {
						cout << "the product is yours now \n";
						prod[i].status = "sold";
						found = true;
						(*pro_buy).category = prod[i].category;
						(*pro_buy).quantity++;
					}
				}
				if (found == false)
					cout << "there is no item number or your price is so low like that \n";
			}
		}
	}

	else{
		cout << "enter the category \n";
		cin.ignore();
		getline(cin, category);
		cout << "enter the price \n";
		cin >> item_price;
		cout << "--------------------------------------------------------\n";
		cout << "-category    -    price    -    item number             \n";
		for (int i = 0; i < size; i++){
			if (prod[i].category == category&&prod[i].starting_bid_price==item_price)
			if (prod[i].status == "available") {
				cout << "-" << prod[i].category << "   -   " << prod[i].starting_bid_price << "   -   " << prod[i].item_number << "-" << "\n";
				found = true;
			}
		}
		cout << "---------------------------------------------------------\n";
		if (found == false)
			cout << "there is no item like that \n";
		if (found == true){
			cout << "if you want buy this item with his price press 1 else if you want to enter new price press 2 \n";
			cin >> choice2;
			if (choice2 == 1){
				cout << "enter the item number please to send the request\n";
				cin >> item_number;
				found = false;
				for (int i = 0; i < size; i++){
					if (prod[i].item_number == item_number)
					if (prod[i].status == "available") {
						cout << "the product is yours now \n";
						prod[i].status = "sold";
						found = true;
						(*pro_buy).category = prod[i].category;
						(*pro_buy).quantity++;
					}
				}
				if (found == false)
					cout << "there is no item number like that \n";
			}
			else{
				cout << "enter the item number and price please to send the request\n";
				cin >> item_number>> price;
				found = false;
				for (int i = 0; i < size; i++){
					if (prod[i].item_number == item_number && (prod[i].starting_bid_price >= price && (prod[i].starting_bid_price - prod[i].starting_bid_price*0.1) <= price))
					if (prod[i].status == "available") {
						cout << "the product is yours now \n";
						prod[i].status = "sold";
						found = true;
						(*pro_buy).category = prod[i].category;
						(*pro_buy).quantity++;
					}
				}
				if (found == false)
					cout << "there is no item number or your price is so low like that \n";
			}
		}

	}

}

void month_best_sel(product *pro_buy, int rows, product *prod, int size){
	product *best= new product [size]();
	int counter=0;
	int max = 0;
	string name_of_product={};
	cout << "category that is the best sell is \n";
	for (int i = 0; i < size; i++){
		for (int j = 0; j < rows; j++){
			if (pro_buy[j].category == prod[i].category)
				counter++;
		}
		best[i].category = prod[i].category;
		best[i].quantity = counter;
	}
	max = best[0].quantity;
	for (int i = 0; i < size; i++){
		if (max < best[i].quantity)
			max = best[i].quantity;
		name_of_product = best[i].category;
	}
	
	cout << "the best sell is "<< name_of_product << "-with quantity-" << max << "\n";
	delete[] best;
	best = NULL;

}