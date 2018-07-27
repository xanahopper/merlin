//
// Created by Xana Hopper on 2018/7/26.
//

#ifndef MERLIN_ASSET_H
#define MERLIN_ASSET_H

#include <memory>
#include <string>

namespace merlin {
    enum assetType : int {
        none = 0,
        video,
        audio,
        image,
        layer
    };

    class Asset {
    public:
        Asset();
        Asset(Asset &&other);

        virtual ~Asset();

        Asset(const Asset &) = delete;
        Asset& operator=(const Asset &) = delete;
    private:
        assetType m_asset_type;
        std::string m_uri;
    };
}


#endif //MERLIN_ASSET_H
