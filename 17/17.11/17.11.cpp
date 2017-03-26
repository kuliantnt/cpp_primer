//
// Created by lianlian on 16-12-13.
//

#include <string>
#include <bitset>
#include <vector>

#ifndef QUIZ
#define QUIZ
template <std::size_t N>
class Quiz{
public:
    //构造函数
    Quiz() = default;
    Quiz(std::string& str) : answer(str) {}
    void update(std::size_t&, bool);
    template <std::size_t bit>
    friend std::size_t grade(Quiz<bit> const& lhs, Quiz<bit> const& rhs);
    template <std::size_t bit>
    friend std::ostream& operator <<(std::ostream& os, Quiz<bit> const&  quiz);

private:
    std::bitset<N> answer;
};

//int main(int argc, char * argv[]){
//
//}

template <std::size_t N>
void Quiz<N>::update(std::size_t &postion, bool b) {
    answer.set(postion, b);
}

template <std::size_t bit>
std::ostream &operator<<(std::ostream &os, Quiz<bit> const & quiz) {
    os << quiz.answer;
    return os;
}

template<std::size_t bit>
std::size_t grade(Quiz<bit> const &lhs, Quiz<bit> const &rhs) {
    std::bitset<bit> result = lhs.answer ^ rhs.answer;
    result.flip();
    return result.count();
}

#endif
