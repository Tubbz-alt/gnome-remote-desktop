/*
 * Copyright (C) 2018 Red Hat Inc.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
 * 02111-1307, USA.
 *
 */

#ifndef GRD_PROMPT_H
#define GRD_PROMPT_H

typedef enum _GrdPromptResponse
{
  GRD_PROMPT_RESPONSE_ACCEPT,
  GRD_PROMPT_RESPONSE_REFUSE
} GrdPromptResponse;

#define GRD_TYPE_PROMPT (grd_prompt_get_type ())
G_DECLARE_FINAL_TYPE (GrdPrompt, grd_prompt, GRD, PROMPT, GObject)

void grd_prompt_query_async (GrdPrompt           *prompt,
                             const char          *remote_host,
                             GCancellable        *cancellable,
                             GAsyncReadyCallback  callback,
                             gpointer             user_data);

gboolean grd_prompt_query_finish (GrdPrompt          *prompt,
                                  GAsyncResult       *result,
                                  GrdPromptResponse  *response,
                                  GError            **error);

#endif /* GRD_PROMPT_H */
