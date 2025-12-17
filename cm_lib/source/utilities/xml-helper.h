#ifndef XML_HELPER_H
#define XML_HELPER_H

#include <QDomNode>
#include <QString>

namespace cm {
namespace utilities {
    class XmlHelper
    {
    public:
        static QString toString(const QDomNode& domNode);
    private:
        XmlHelper() {}
        static void appendNode(const QDomNode& domNode, QString& output);
    };
}}

#endif // XML_HELPER_H
