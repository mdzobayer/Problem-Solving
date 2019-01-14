#include <string>

std::string get_a_string() {
    std::string a = "bob";
    return a;
    //return std::move(a);
}

int main(){

    return get_a_string().size();
}
