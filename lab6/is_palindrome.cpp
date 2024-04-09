template<typename Iterator, typename Equality>
bool is_palindrome(Iterator begin, Iterator end, Equality equal) {
    Iterator it1 = begin;
    Iterator it2 = end;
    --it2;

    while (it1 < it2) {
        if (!equal(*it1, *it2)) {
            return false;
        }
        ++it1;
        --it2;
    }
    return true;
}
