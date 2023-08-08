    // Excerpt from the book: Scott Meyers, "Effective C++ (2005)", Itens 27
    // C++ also offers four new cast forms (often called new-style or C++-style casts):
    // ¡ö const_cast<T>(expression)
    // ¡ö dynamic_cast<T>(expression)
    // ¡ö reinterpret_cast<T>(expression)
    // ¡ö static_cast<T>(expression)

    // Each serves a distinct purpose:
    // ¡ö const_cast is typically used to cast away the constness of objects. 
    //      It is the only C++-style cast that can do this.
    // ¡ö dynamic_cast is primarily used to perform ¡°safe downcasting,¡± i.e., 
    //      to determine whether an object is of a particular type in an inheritance hierarchy. 
    //      It is the only cast that cannot be performed using the old-style syntax. 
    //      It is also the only cast that may have a significant runtime cost. 
    //      (I¡¯ll provide details on this a bit later.)
    // ¡ö reinterpret_cast is intended for low-level casts that yield implementation-dependent 
    //      (i.e., unportable) results, e.g., casting a pointer to an int. Such casts should be rare outside 
    //      low-level code. I use it only once in this book, and that¡¯s only when discussing how you might 
    //      write a debugging allocator for raw memory (see Item 50).
    // ¡ö static_cast can be used to force implicit conversions (e.g., non-const object to const object 
    //      (as in Item 3), int to double, etc.). 
    //      It can also be used to perform the reverse of many such conversions 
    //      (e.g., void* pointers to typed pointers, pointer-to-base to pointer-to-derived), 
    //      though it cannot cast from const to non-const objects. (Only const_cast can do that.)
