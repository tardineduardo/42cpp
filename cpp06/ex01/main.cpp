#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

struct Sample
{
    int a;
    int b;
};

int main()
{
    Sample samples[2];
    samples[0].a = 1;
    samples[0].b = 2;
    samples[1].a = 10;
    samples[1].b = 20;

    Data data[2];
    data[0].ptr = &samples[0];
    data[1].ptr = &samples[1];

    for (int i = 0; i < 2; ++i)
    {
        Data *original = &data[i];

        uintptr_t raw = Serializer::serialize(original);
        Data *decoded = Serializer::deserialize(raw);

        std::cout << "=== index " << i << " ===" << std::endl;
        std::cout << "original pointer: " << original << std::endl;
        std::cout << "raw uintptr_t   : " << raw << std::endl;
        std::cout << "decoded pointer : " << decoded << std::endl;

        if (decoded == original)
            std::cout << "pointers match ✅" << std::endl;
        else
            std::cout << "pointers do NOT match ❌" << std::endl;

        // Show that the payload is still accessible.
        Sample *p = static_cast<Sample *>(decoded->ptr);
        std::cout << "Sample.a = " << p->a << ", Sample.b = " << p->b << std::endl;
        std::cout << std::endl;
    }

    return 0;
}