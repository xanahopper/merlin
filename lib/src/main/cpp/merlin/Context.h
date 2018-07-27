//
// Created by Xana Hopper on 2018/7/26.
//

#ifndef MERLIN_CONTEXT_H
#define MERLIN_CONTEXT_H

#include <memory>
#include <queue>

namespace merlin {
    class Context {
    public:
        Context();
        Context(Context &&other);   // 移动构造函数

        ~Context();

        Context(const Context &) = delete; // 禁止复制
        Context& operator=(const Context &) = delete; // 禁止复制
    private:
        bool setup();

    private:
        std::shared_ptr<AVFormatContext> p_format_context;
    };
}

#endif //MERLIN_CONTEXT_H
