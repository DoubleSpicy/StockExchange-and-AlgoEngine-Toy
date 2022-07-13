#ifndef FIX_PARSER_HPP
#define FIX_PARSER_HPP
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <iomanip>
#include <type_traits>
#include <algorithm>

// template<class T>
// typename std::enable_if<!std::numeric_limits<T>::is_integer, bool>::type almost_equal(T x, T y, int ulp);

namespace FIX{



    class message{
        public:
            message();
            // ~message();
            virtual std::string to_string() = 0;
            // virtual ~message();
    };
    class order: message{
        public:
            std::string MsgType;
            std::string OrderID;
            float OrderQty;
            std::string OrdType;
            float Price;
            std::string SenderCompID;
            long SendingTime;
            std::string Side;
            float POVTargetPercentage;

            order();

            order(const std::string &MsgType,
                const std::string &OrderID, 
                const float &OrderQty, 
                const std::string &OrdType,
                const float &Price,
                const std::string &SenderCompID,
                const long &SendingTime,
                const std::string &Side, 
                const float &POVTargetPercentage);

            order(const std::string &msg);

            std::string to_string() override;

            // inline bool compareID(const order & other) const;
            // inline bool operator> (const order & other) const;
            // inline bool operator< (const order & other) const;
            // inline bool operator>= (const order & other) const;
            // inline bool operator<= (const order & other) const;
            
            // ~order();
    };
    
    class ACK: message{
        // conveying ACK ORDER or ACK FILL or ACK CANCELLED message
        public:
            std::string TargetCompID; // to send to specific client
            std::string MsgType; // ACK ORDER / ACK FILL / ACK CANCELLED
            std::string OrderID; // original order id
            float OrderQty; // quantity invloved
            ACK(const std::string & TargetCompID,
                const std::string & MsgType,
                const std::string OrderID,
                const float & OrderQty);
            std::string to_string() override;
    };

    std::vector<FIX::order> parseQuotes(const std::string & marketData);

};

















#endif