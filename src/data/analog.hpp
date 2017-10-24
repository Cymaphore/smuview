/*
 * This file is part of the SmuView project.
 *
 * Copyright (C) 2012 Joel Holdsworth <joel@airwebreathe.org.uk>
 * Copyright (C) 2017 Frank Stettner <frank-stettner@gmx.net>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see <http://www.gnu.org/licenses/>.
 */

#ifndef DATA_ANALOG_HPP
#define DATA_ANALOG_HPP

#include <deque>
#include <memory>

#include <QObject>

#include "signaldata.hpp"

using std::deque;
using std::shared_ptr;
using std::vector;

namespace sv {
namespace data {

class AnalogSegment;

class Analog : public SignalData
{
	Q_OBJECT

public:
	Analog();

	void push_segment(shared_ptr<AnalogSegment> &segment);

	const deque< shared_ptr<AnalogSegment> >& analog_segments() const;

	vector< shared_ptr<Segment> > segments() const;

	void clear();

	uint64_t max_sample_count() const;

	void notify_samples_added(QObject* segment, uint64_t start_sample,
		uint64_t end_sample);

	void notify_min_max_changed(float min, float max);

Q_SIGNALS:
	void samples_cleared();

	void samples_added(QObject* segment, uint64_t start_sample,
		uint64_t end_sample);

	void min_max_changed(float min, float max);

private:
	deque< shared_ptr<AnalogSegment> > segments_;
};

} // namespace data
} // namespace sv

#endif // DATA_ANALOG_HPP
