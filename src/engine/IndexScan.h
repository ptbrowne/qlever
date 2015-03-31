// Copyright 2015, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Björn Buchhold (buchhold@informatik.uni-freiburg.de)
#pragma once

#include <string>
#include <grp.h>
#include "./Operation.h"

using std::string;

class IndexScan : public Operation {
public:
  enum ScanType {
    PSO_BOUND_S = 0,
    POS_BOUND_O = 1,
    PSO_FREE_S = 2,
    POS_FREE_O = 3
  };

  virtual string asString() const;

  IndexScan(QueryExecutionContext* qec, ScanType type) :
      Operation(qec), _type(type) {
  }

  virtual ~IndexScan() { }

  void setSubject(const string& subject) {
    _subject = subject;
  }

  void setPredicate(const string& predicate) {
    _predicate = predicate;
  }

  void setObject(const string& object) {
    _object = object;
  }

  virtual size_t getResultWidth() const;
  virtual size_t resultSortedOn() const { return 0; }

private:
  ScanType _type;
  string _subject;
  string _predicate;
  string _object;

  virtual void computeResult(ResultTable* result) const;

  void computePSOboundS(ResultTable* result) const;
  void computePSOfreeS(ResultTable* result) const;
  void computePOSboundO(ResultTable* result) const;
  void computePOSfreeO(ResultTable* result) const;
};
