/************************************************************************************
      
 *                 Copyright (C) 2021 - 2023, Barca, Inc. 
 
 *    Email: <opensource@barca.com>  GitHub: @BarcaWebCloud. 
 *    Project: BSCAN to scanner MotherBoards. CPU, Memory Ram, SO and more
 
 * This software is licensed as described in the file COPYING, which                    
 * you should have received as part of this distribution. The terms                     
 * are also available at https://project-barca.github.io/docs/copyright.html.           
 *
 * You may opt to use, copy, modify, merge, publish, distribute and/or sell             
 * copies of the Software, and permit persons to whom the Software is                   
 * furnished to do so, under the terms of the COPYING file.                             
 *
 * This software is distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY            
 * KIND, either express or implied.                                                      
 *
 **************************************************************************************/
#pragma once

#include <string>

namespace bscan {

  class Browser {
   public:
    Browser();
    ~Browser() = default;

    std::string chromehistory();
    std::string chromemedia();
    std::string chromelogin();
    std::string chromepreferences();
    std::string chromesecurepreferences();
    std::string chromeshortcuts();
    std::string chromememberof();
    std::string chromeautofillemails();
    std::string chromeautofilladdresses();
    std::string chromeautofillphones();
    std::string chromeautofillnames();
    std::string chromeautofillprofiles();
    std::string profile();
    std::string visitedlinks();
    std::string watched();
    std::string downloads();
    std::string bookmarks();
    std::string preferencies();
    std::string extensions();
    std::string apps();
    std::string logs();
    
    static std::string getChromeHistory();
    static std::string getChromeMedia();
    static std::string getChromeLogin();
    static std::string getChromeShortcuts();
    static std::string getChromeMemberOf();
    static std::string getChromeAutoFillEmails();
    static std::string getChromeAutoFillAddresses();
    static std::string getChromeAutoFillPhones();
    static std::string getChromeAutoFillNames();
    static std::string getChromeAutoFillProfiles();
    static std::string getProfile();
    static std::string getVisitedLinks();
    static std::string getWatched();
    static std::string getDownloads();
    static std::string getBookmarks();
    static std::string getPreferencies();
    static std::string getExtensions();
    static std::string getApps();
    static std::string getLogs();

   private:
    std::string _chromehistory;
    std::string _chromemedia;
    std::string _chromelogin;
    std::string _chromeshortcuts;
    std::string _chromememberof;
    std::string _chromeautofillemails;
    std::string _chromeautofilladdresses;
    std::string _chromeautofillphones;
    std::string _chromeautofillnames;
    std::string _chromeautofillprofiles;
    std::string _profile;
    std::string _visitedlinks;
    std::string _watched;
    std::string _downloads;
    std::string _bookmarks;
    std::string _preferencies;
    std::string _extensions;
    std::string _apps;
    std::string _logs;
  };

};