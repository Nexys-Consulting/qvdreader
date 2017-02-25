/*
 * Copyright (c) 2017 Devin Smith <devin@devinsmith.net>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef __QVDFILE_H__
#define __QVDFILE_H__

#include <string>
#include <vector>
#include <expat.h>

#include <LineageInfo.h>
#include <QvdField.h>
#include <QvdTableHeader.h>

class QvdFile {
public:
  bool Load(const char *filename);

  void startElement(const XML_Char *name, const XML_Char **attrs);
  void endElement(const XML_Char *name);
  void charData(const XML_Char *s, int len);

private:
  QvdTableHeader _hdr;
  std::vector<QvdField> _fields;
  std::vector<QvdLineageInfo> _lineages;

  int _state;
  int _prevState;
  std::string _currentTag;
  std::string _data;
};

#endif /* __QVDFILE_H__ */

