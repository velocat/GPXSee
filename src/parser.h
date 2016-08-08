#ifndef PARSER_H
#define PARSER_H

#include <QXmlStreamReader>
#include <QVector>
#include <QList>
#include "trackpoint.h"
#include "waypoint.h"


class Parser
{
public:
	Parser(QList<QVector<Trackpoint> > &tracks,
	  QList<QVector<Waypoint> > &routes, QList<Waypoint> &waypoints)
	  : _tracks(tracks), _routes(routes), _waypoints(waypoints)
	  {_track = 0; _route = 0;}

	bool loadFile(QIODevice *device);
	QString errorString() const {return _reader.errorString();}
	int errorLine() const {return _reader.lineNumber();}

private:
	enum DataType {
		Name, Description, Elevation, Time, Geoidheight, Speed, HeartRate,
		Temperature
	};

	bool parse();
	void gpx();
	void track();
	void trackpoints();
	void routepoints();
	void tpExtension();
	void extensions();
	void trackpointData();
	void routepointData();
	void waypointData();

	void handleWaypointAttributes(const QXmlStreamAttributes &attr);
	void handleWaypointData(DataType type, const QString &value);
	void handleTrackpointAttributes(const QXmlStreamAttributes &attr);
	void handleTrackpointData(DataType type, const QString &value);
	void handleRoutepointAttributes(const QXmlStreamAttributes &attr);
	void handleRoutepointData(DataType type, const QString &value);

	QXmlStreamReader _reader;
	QList<QVector<Trackpoint> > &_tracks;
	QList<QVector<Waypoint> > &_routes;
	QList<Waypoint> &_waypoints;
	QVector<Trackpoint> *_track;
	QVector<Waypoint> *_route;
};

#endif // PARSER_H
