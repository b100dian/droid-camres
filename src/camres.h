#ifndef CAMRES_H
#define CAMRES_H
#include <QObject>

#include <gst/gst.h>

class Q_DECL_EXPORT Camres : public QObject
{
    Q_OBJECT

public:
    explicit Camres(QObject *parent = 0);
    virtual ~Camres();

    QList<QPair<QString, int> > getCameras();
    QList<QPair<QString, QStringList> > getResolutions(int cam, QStringList whichCaps, gint& direction);
    static QString aspectRatioForResolution(const QString& size);
    static QString findBestViewFinderForResolution(const QString& size, const QList<QPair<QString, QStringList> > &resolutions, const QRect &screenGeometry);

private:
    QStringList parse(GstCaps *caps);
};


#endif // CAMRES_H
