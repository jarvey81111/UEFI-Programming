/**
  Get current time application
**/

#include <Uefi.h>
#include <Library/UefiLib.h>
#include <Library/DebugLib.h>
#include <Library/ShellCEntryLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/UefiRuntimeServicesTableLib.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Get current time.
 *
 * Using the gBS and gST to get current time.
 *
 */

int main (
  IN int Argc,
  IN char **argv
  )
{
  EFI_STATUS Status;
  EFI_TIME ET;

  printf("Entry of Get Current Time!!\n");

  //  delay 2s
  Status = gBS->Stall(2000);
  ASSERT_EFI_ERROR (Status);
  //  get current time
  Status = gRT->GetTime(&ET,NULL);
  printf("%d-%d-%d %02d:%02d:%02d\n", ET.Year, ET.Month, ET.Day, ET.Hour, ET.Minute, ET.Second);
  ASSERT_EFI_ERROR (Status);
  //  using systemtable to print the message
  Status = gST->ConOut->OutputString(gST->ConOut,L"SystemTable test to print\n");
  ASSERT_EFI_ERROR (Status);
  return Status;
}