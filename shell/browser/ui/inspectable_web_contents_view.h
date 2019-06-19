// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Copyright (c) 2013 Adam Roben <adam@roben.org>. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE-CHROMIUM file.

#ifndef SHELL_BROWSER_UI_INSPECTABLE_WEB_CONTENTS_VIEW_H_
#define SHELL_BROWSER_UI_INSPECTABLE_WEB_CONTENTS_VIEW_H_

#include "base/strings/string16.h"
#include "ui/gfx/native_widget_types.h"

class DevToolsContentsResizingStrategy;

#if defined(TOOLKIT_VIEWS)
namespace views {
class View;
}
#endif

namespace atom {

class InspectableWebContentsViewDelegate;

class InspectableWebContentsView {
 public:
  InspectableWebContentsView() : delegate_(nullptr) {}
  virtual ~InspectableWebContentsView() {}

  // The delegate manages its own life.
  void SetDelegate(InspectableWebContentsViewDelegate* delegate) {
    delegate_ = delegate;
  }
  InspectableWebContentsViewDelegate* GetDelegate() const { return delegate_; }

#if defined(TOOLKIT_VIEWS) && !defined(OS_MACOSX)
  // Returns the container control, which has devtools view attached.
  virtual views::View* GetView() = 0;

  // Returns the web view control, which can be used by the
  // GetInitiallyFocusedView() to set initial focus to web view.
  virtual views::View* GetWebView() = 0;
#else
  virtual gfx::NativeView GetNativeView() const = 0;
#endif

  virtual void ShowDevTools(bool activate) = 0;
  // Hide the DevTools view.
  virtual void CloseDevTools() = 0;
  virtual bool IsDevToolsViewShowing() = 0;
  virtual bool IsDevToolsViewFocused() = 0;
  virtual void SetIsDocked(bool docked, bool activate) = 0;
  virtual void SetContentsResizingStrategy(
      const DevToolsContentsResizingStrategy& strategy) = 0;
  virtual void SetTitle(const base::string16& title) = 0;

 private:
  InspectableWebContentsViewDelegate* delegate_;  // weak references.
};

}  // namespace atom

#endif  // SHELL_BROWSER_UI_INSPECTABLE_WEB_CONTENTS_VIEW_H_
