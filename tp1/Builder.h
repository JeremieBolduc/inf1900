
template <class T>
class Builder
{
public:
    virtual ~Builder() {}
    virtual T build() const = 0;

protected:
    T product;
    T *trash;
    int trashSize;
};