// Copyright (c) 2015 GitHub, Inc.
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#ifndef SHELL_BROWSER_ATOM_QUOTA_PERMISSION_CONTEXT_H_
#define SHELL_BROWSER_ATOM_QUOTA_PERMISSION_CONTEXT_H_

#include "content/public/browser/quota_permission_context.h"
#include "content/public/common/storage_quota_params.h"

namespace atom {

class AtomQuotaPermissionContext : public content::QuotaPermissionContext {
 public:
  typedef content::QuotaPermissionContext::QuotaPermissionResponse response;

  AtomQuotaPermissionContext();

  // content::QuotaPermissionContext:
  void RequestQuotaPermission(const content::StorageQuotaParams& params,
                              int render_process_id,
                              const PermissionCallback& callback) override;

 private:
  ~AtomQuotaPermissionContext() override;

  DISALLOW_COPY_AND_ASSIGN(AtomQuotaPermissionContext);
};

}  // namespace atom

#endif  // SHELL_BROWSER_ATOM_QUOTA_PERMISSION_CONTEXT_H_
