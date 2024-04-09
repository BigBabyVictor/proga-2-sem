template<typename Iterator, typename Comparator>
bool is_sorted(Iterator begin, Iterator end, Comparator comp) {
    Iterator prev = begin;
    for (Iterator it = ++begin; it != end; ++it) {
        if (!comp(*prev, *it)) {
            return false;
        }
        prev = it;
    }
    return true;
}
