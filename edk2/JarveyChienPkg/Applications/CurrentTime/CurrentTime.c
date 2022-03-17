/**
  Get current time application
**/

#include <Uefi.h>
#include <Library/UefiLib.h>
#include <Library/DebugLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/UefiRuntimeServicesTableLib.h>

/**
 * Get current time.
 *
 * Using the gBS and gST to get current time.
 *
 * @param ImageHandle   The firmware allocated handle for the EFI image.
 * @param SystemTable   A pointer to the EFI System Table.
 * @return EFI_STATUS   EFI_SUCCESS means that application is fine.
 */

EFI_STATUS
EFIAPI
UefiMain (
  IN EFI_HANDLE ImageHandle,
  IN EFI_SYSTEM_TABLE *SystemTable
  )
{
  EFI_STATUS Status;
  EFI_TIME ET;

  Print(L"Entry of Get Current Time!!\n");

  //  delay 2s
  Status = gBS->Stall(2000);
  ASSERT_EFI_ERROR (Status);
  //  get current time
  Status = gRT->GetTime(&ET,NULL);
  Print(L"%d-%d-%d %02d:%02d:%02d", ET.Year, ET.Month, ET.Day, ET.Hour, ET.Minute, ET.Second);
  ASSERT_EFI_ERROR (Status);
  //  using systemtable to print the message
  Status = gST->ConOut->OutputString(SystemTable->ConOut,L"SystemTable test to print");
  ASSERT_EFI_ERROR (Status);
  return Status;
}