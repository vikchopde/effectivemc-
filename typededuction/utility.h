#ifndef EFFECTIVEC_UTILITY_H
#define EFFECTIVEC_UTILITY_H

#if defined(COMMENT_MAIN)
    #define MAIN_FUNC //auto main(int argc, char* argv[]) \
                        //      ->int                       \

#else
    #define MAIN_FUNC auto main(int argc, char* argv[]) \
                             ->int                      \

    #endif

#endif //EFFECTIVEC_UTILITY_H
