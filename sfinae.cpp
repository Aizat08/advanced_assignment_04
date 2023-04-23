#include <iostream>
#include <vector>
#include <list>
#include <bitset>
#include <string>
#include <type_traits>

//metafunctions => type traits for containers
template <typename T>
struct is_container {
	static const bool value = false; };

template <typename T>
struct is_container<std::vector<T>> {
	static const bool value = true; };

template <typename T>
struct is_container<std::list<T>> {
	static const bool value = true; };

//print function for containers
template <typename T>
void print_ip(const T& data, std::enable_if_t<is_container<T>::value>* = 0){

	for(auto it = std::begin(data); it!=std::end(data); ++it){
		if(it!=std::begin(data)){std::cout << ".";}

		std::cout << *it; }

	std::cout << std::endl;
}

//template function to separate every 8 bits 
template<typename T>
std::string separate(int upper, int lower, std::bitset<sizeof(T)*8>& binary){
    std::string ss = "";
    for(int i=upper-1; i>=lower; i--){
        ss += std::to_string(binary[i]); }
    return ss; }

//print function for integral types
template <typename T>
void print_ip(const T& data, std::enable_if_t<std::is_integral_v<T>>* = 0){

	size_t byte = 8;
	std::bitset<sizeof(T)*8> binary(data);

    std::vector<int> vector;
	for(int i = binary.size(); i>0; i--){

        int _upper = i;
        int _lower = i - byte;

        if(_upper%byte==0 && _lower%byte==0 ){

            std::bitset<8> binary1(separate<T>(_upper, _lower, binary));
            vector.push_back(binary1.to_ulong()); }
    }
    print_ip(vector);
}

//print function for string
template <typename T>
void print_ip(const T& data, std::enable_if_t<std::is_same_v<T, std::string>>* = 0){
	std::cout << data << std::endl;
}

int main(){

	print_ip(int8_t{-1});
	print_ip(int16_t{0}); 
	print_ip(int32_t{2130706433});
	print_ip(int64_t{8875824491850138409});
	print_ip(std::string{"Hello, World!"});
	print_ip(std::vector<int>{100, 200, 300, 400}); 
	print_ip(std::list<short>{400, 300, 200, 100});
}
