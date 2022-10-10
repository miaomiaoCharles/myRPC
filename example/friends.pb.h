// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: friends.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_friends_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_friends_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3011000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3011000 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/service.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_friends_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_friends_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxillaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[4]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_friends_2eproto;
namespace lqc {
class getFriendsRequest;
class getFriendsRequestDefaultTypeInternal;
extern getFriendsRequestDefaultTypeInternal _getFriendsRequest_default_instance_;
class getFriendsResponse;
class getFriendsResponseDefaultTypeInternal;
extern getFriendsResponseDefaultTypeInternal _getFriendsResponse_default_instance_;
class resCode;
class resCodeDefaultTypeInternal;
extern resCodeDefaultTypeInternal _resCode_default_instance_;
class user;
class userDefaultTypeInternal;
extern userDefaultTypeInternal _user_default_instance_;
}  // namespace lqc
PROTOBUF_NAMESPACE_OPEN
template<> ::lqc::getFriendsRequest* Arena::CreateMaybeMessage<::lqc::getFriendsRequest>(Arena*);
template<> ::lqc::getFriendsResponse* Arena::CreateMaybeMessage<::lqc::getFriendsResponse>(Arena*);
template<> ::lqc::resCode* Arena::CreateMaybeMessage<::lqc::resCode>(Arena*);
template<> ::lqc::user* Arena::CreateMaybeMessage<::lqc::user>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace lqc {

// ===================================================================

class resCode :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:lqc.resCode) */ {
 public:
  resCode();
  virtual ~resCode();

  resCode(const resCode& from);
  resCode(resCode&& from) noexcept
    : resCode() {
    *this = ::std::move(from);
  }

  inline resCode& operator=(const resCode& from) {
    CopyFrom(from);
    return *this;
  }
  inline resCode& operator=(resCode&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const resCode& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const resCode* internal_default_instance() {
    return reinterpret_cast<const resCode*>(
               &_resCode_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(resCode& a, resCode& b) {
    a.Swap(&b);
  }
  inline void Swap(resCode* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline resCode* New() const final {
    return CreateMaybeMessage<resCode>(nullptr);
  }

  resCode* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<resCode>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const resCode& from);
  void MergeFrom(const resCode& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(resCode* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "lqc.resCode";
  }
  private:
  inline ::PROTOBUF_NAMESPACE_ID::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_friends_2eproto);
    return ::descriptor_table_friends_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kErrmsgFieldNumber = 2,
    kErrcodeFieldNumber = 1,
  };
  // bytes errmsg = 2;
  void clear_errmsg();
  const std::string& errmsg() const;
  void set_errmsg(const std::string& value);
  void set_errmsg(std::string&& value);
  void set_errmsg(const char* value);
  void set_errmsg(const void* value, size_t size);
  std::string* mutable_errmsg();
  std::string* release_errmsg();
  void set_allocated_errmsg(std::string* errmsg);
  private:
  const std::string& _internal_errmsg() const;
  void _internal_set_errmsg(const std::string& value);
  std::string* _internal_mutable_errmsg();
  public:

  // int32 errcode = 1;
  void clear_errcode();
  ::PROTOBUF_NAMESPACE_ID::int32 errcode() const;
  void set_errcode(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_errcode() const;
  void _internal_set_errcode(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // @@protoc_insertion_point(class_scope:lqc.resCode)
 private:
  class _Internal;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr errmsg_;
  ::PROTOBUF_NAMESPACE_ID::int32 errcode_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_friends_2eproto;
};
// -------------------------------------------------------------------

class user :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:lqc.user) */ {
 public:
  user();
  virtual ~user();

  user(const user& from);
  user(user&& from) noexcept
    : user() {
    *this = ::std::move(from);
  }

  inline user& operator=(const user& from) {
    CopyFrom(from);
    return *this;
  }
  inline user& operator=(user&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const user& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const user* internal_default_instance() {
    return reinterpret_cast<const user*>(
               &_user_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(user& a, user& b) {
    a.Swap(&b);
  }
  inline void Swap(user* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline user* New() const final {
    return CreateMaybeMessage<user>(nullptr);
  }

  user* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<user>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const user& from);
  void MergeFrom(const user& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(user* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "lqc.user";
  }
  private:
  inline ::PROTOBUF_NAMESPACE_ID::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_friends_2eproto);
    return ::descriptor_table_friends_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kNameFieldNumber = 2,
    kIdFieldNumber = 1,
  };
  // bytes name = 2;
  void clear_name();
  const std::string& name() const;
  void set_name(const std::string& value);
  void set_name(std::string&& value);
  void set_name(const char* value);
  void set_name(const void* value, size_t size);
  std::string* mutable_name();
  std::string* release_name();
  void set_allocated_name(std::string* name);
  private:
  const std::string& _internal_name() const;
  void _internal_set_name(const std::string& value);
  std::string* _internal_mutable_name();
  public:

  // uint32 id = 1;
  void clear_id();
  ::PROTOBUF_NAMESPACE_ID::uint32 id() const;
  void set_id(::PROTOBUF_NAMESPACE_ID::uint32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint32 _internal_id() const;
  void _internal_set_id(::PROTOBUF_NAMESPACE_ID::uint32 value);
  public:

  // @@protoc_insertion_point(class_scope:lqc.user)
 private:
  class _Internal;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr name_;
  ::PROTOBUF_NAMESPACE_ID::uint32 id_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_friends_2eproto;
};
// -------------------------------------------------------------------

class getFriendsRequest :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:lqc.getFriendsRequest) */ {
 public:
  getFriendsRequest();
  virtual ~getFriendsRequest();

  getFriendsRequest(const getFriendsRequest& from);
  getFriendsRequest(getFriendsRequest&& from) noexcept
    : getFriendsRequest() {
    *this = ::std::move(from);
  }

  inline getFriendsRequest& operator=(const getFriendsRequest& from) {
    CopyFrom(from);
    return *this;
  }
  inline getFriendsRequest& operator=(getFriendsRequest&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const getFriendsRequest& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const getFriendsRequest* internal_default_instance() {
    return reinterpret_cast<const getFriendsRequest*>(
               &_getFriendsRequest_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  friend void swap(getFriendsRequest& a, getFriendsRequest& b) {
    a.Swap(&b);
  }
  inline void Swap(getFriendsRequest* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline getFriendsRequest* New() const final {
    return CreateMaybeMessage<getFriendsRequest>(nullptr);
  }

  getFriendsRequest* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<getFriendsRequest>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const getFriendsRequest& from);
  void MergeFrom(const getFriendsRequest& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(getFriendsRequest* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "lqc.getFriendsRequest";
  }
  private:
  inline ::PROTOBUF_NAMESPACE_ID::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_friends_2eproto);
    return ::descriptor_table_friends_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kIdFieldNumber = 1,
  };
  // uint32 id = 1;
  void clear_id();
  ::PROTOBUF_NAMESPACE_ID::uint32 id() const;
  void set_id(::PROTOBUF_NAMESPACE_ID::uint32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint32 _internal_id() const;
  void _internal_set_id(::PROTOBUF_NAMESPACE_ID::uint32 value);
  public:

  // @@protoc_insertion_point(class_scope:lqc.getFriendsRequest)
 private:
  class _Internal;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::uint32 id_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_friends_2eproto;
};
// -------------------------------------------------------------------

class getFriendsResponse :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:lqc.getFriendsResponse) */ {
 public:
  getFriendsResponse();
  virtual ~getFriendsResponse();

  getFriendsResponse(const getFriendsResponse& from);
  getFriendsResponse(getFriendsResponse&& from) noexcept
    : getFriendsResponse() {
    *this = ::std::move(from);
  }

  inline getFriendsResponse& operator=(const getFriendsResponse& from) {
    CopyFrom(from);
    return *this;
  }
  inline getFriendsResponse& operator=(getFriendsResponse&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const getFriendsResponse& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const getFriendsResponse* internal_default_instance() {
    return reinterpret_cast<const getFriendsResponse*>(
               &_getFriendsResponse_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    3;

  friend void swap(getFriendsResponse& a, getFriendsResponse& b) {
    a.Swap(&b);
  }
  inline void Swap(getFriendsResponse* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline getFriendsResponse* New() const final {
    return CreateMaybeMessage<getFriendsResponse>(nullptr);
  }

  getFriendsResponse* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<getFriendsResponse>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const getFriendsResponse& from);
  void MergeFrom(const getFriendsResponse& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(getFriendsResponse* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "lqc.getFriendsResponse";
  }
  private:
  inline ::PROTOBUF_NAMESPACE_ID::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_friends_2eproto);
    return ::descriptor_table_friends_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kFriendsFieldNumber = 1,
    kResFieldNumber = 2,
  };
  // repeated .lqc.user friends = 1;
  int friends_size() const;
  private:
  int _internal_friends_size() const;
  public:
  void clear_friends();
  ::lqc::user* mutable_friends(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::lqc::user >*
      mutable_friends();
  private:
  const ::lqc::user& _internal_friends(int index) const;
  ::lqc::user* _internal_add_friends();
  public:
  const ::lqc::user& friends(int index) const;
  ::lqc::user* add_friends();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::lqc::user >&
      friends() const;

  // .lqc.resCode res = 2;
  bool has_res() const;
  private:
  bool _internal_has_res() const;
  public:
  void clear_res();
  const ::lqc::resCode& res() const;
  ::lqc::resCode* release_res();
  ::lqc::resCode* mutable_res();
  void set_allocated_res(::lqc::resCode* res);
  private:
  const ::lqc::resCode& _internal_res() const;
  ::lqc::resCode* _internal_mutable_res();
  public:

  // @@protoc_insertion_point(class_scope:lqc.getFriendsResponse)
 private:
  class _Internal;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::lqc::user > friends_;
  ::lqc::resCode* res_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_friends_2eproto;
};
// ===================================================================

class FriendsServiceRpc_Stub;

class FriendsServiceRpc : public ::PROTOBUF_NAMESPACE_ID::Service {
 protected:
  // This class should be treated as an abstract interface.
  inline FriendsServiceRpc() {};
 public:
  virtual ~FriendsServiceRpc();

  typedef FriendsServiceRpc_Stub Stub;

  static const ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor* descriptor();

  virtual void getFriends(::PROTOBUF_NAMESPACE_ID::RpcController* controller,
                       const ::lqc::getFriendsRequest* request,
                       ::lqc::getFriendsResponse* response,
                       ::google::protobuf::Closure* done);

  // implements Service ----------------------------------------------

  const ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor* GetDescriptor();
  void CallMethod(const ::PROTOBUF_NAMESPACE_ID::MethodDescriptor* method,
                  ::PROTOBUF_NAMESPACE_ID::RpcController* controller,
                  const ::PROTOBUF_NAMESPACE_ID::Message* request,
                  ::PROTOBUF_NAMESPACE_ID::Message* response,
                  ::google::protobuf::Closure* done);
  const ::PROTOBUF_NAMESPACE_ID::Message& GetRequestPrototype(
    const ::PROTOBUF_NAMESPACE_ID::MethodDescriptor* method) const;
  const ::PROTOBUF_NAMESPACE_ID::Message& GetResponsePrototype(
    const ::PROTOBUF_NAMESPACE_ID::MethodDescriptor* method) const;

 private:
  GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(FriendsServiceRpc);
};

class FriendsServiceRpc_Stub : public FriendsServiceRpc {
 public:
  FriendsServiceRpc_Stub(::PROTOBUF_NAMESPACE_ID::RpcChannel* channel);
  FriendsServiceRpc_Stub(::PROTOBUF_NAMESPACE_ID::RpcChannel* channel,
                   ::PROTOBUF_NAMESPACE_ID::Service::ChannelOwnership ownership);
  ~FriendsServiceRpc_Stub();

  inline ::PROTOBUF_NAMESPACE_ID::RpcChannel* channel() { return channel_; }

  // implements FriendsServiceRpc ------------------------------------------

  void getFriends(::PROTOBUF_NAMESPACE_ID::RpcController* controller,
                       const ::lqc::getFriendsRequest* request,
                       ::lqc::getFriendsResponse* response,
                       ::google::protobuf::Closure* done);
 private:
  ::PROTOBUF_NAMESPACE_ID::RpcChannel* channel_;
  bool owns_channel_;
  GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(FriendsServiceRpc_Stub);
};


// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// resCode

// int32 errcode = 1;
inline void resCode::clear_errcode() {
  errcode_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 resCode::_internal_errcode() const {
  return errcode_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 resCode::errcode() const {
  // @@protoc_insertion_point(field_get:lqc.resCode.errcode)
  return _internal_errcode();
}
inline void resCode::_internal_set_errcode(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  errcode_ = value;
}
inline void resCode::set_errcode(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_errcode(value);
  // @@protoc_insertion_point(field_set:lqc.resCode.errcode)
}

// bytes errmsg = 2;
inline void resCode::clear_errmsg() {
  errmsg_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline const std::string& resCode::errmsg() const {
  // @@protoc_insertion_point(field_get:lqc.resCode.errmsg)
  return _internal_errmsg();
}
inline void resCode::set_errmsg(const std::string& value) {
  _internal_set_errmsg(value);
  // @@protoc_insertion_point(field_set:lqc.resCode.errmsg)
}
inline std::string* resCode::mutable_errmsg() {
  // @@protoc_insertion_point(field_mutable:lqc.resCode.errmsg)
  return _internal_mutable_errmsg();
}
inline const std::string& resCode::_internal_errmsg() const {
  return errmsg_.GetNoArena();
}
inline void resCode::_internal_set_errmsg(const std::string& value) {
  
  errmsg_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
}
inline void resCode::set_errmsg(std::string&& value) {
  
  errmsg_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:lqc.resCode.errmsg)
}
inline void resCode::set_errmsg(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  errmsg_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:lqc.resCode.errmsg)
}
inline void resCode::set_errmsg(const void* value, size_t size) {
  
  errmsg_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:lqc.resCode.errmsg)
}
inline std::string* resCode::_internal_mutable_errmsg() {
  
  return errmsg_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* resCode::release_errmsg() {
  // @@protoc_insertion_point(field_release:lqc.resCode.errmsg)
  
  return errmsg_.ReleaseNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void resCode::set_allocated_errmsg(std::string* errmsg) {
  if (errmsg != nullptr) {
    
  } else {
    
  }
  errmsg_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), errmsg);
  // @@protoc_insertion_point(field_set_allocated:lqc.resCode.errmsg)
}

// -------------------------------------------------------------------

// user

// uint32 id = 1;
inline void user::clear_id() {
  id_ = 0u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 user::_internal_id() const {
  return id_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 user::id() const {
  // @@protoc_insertion_point(field_get:lqc.user.id)
  return _internal_id();
}
inline void user::_internal_set_id(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  
  id_ = value;
}
inline void user::set_id(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _internal_set_id(value);
  // @@protoc_insertion_point(field_set:lqc.user.id)
}

// bytes name = 2;
inline void user::clear_name() {
  name_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline const std::string& user::name() const {
  // @@protoc_insertion_point(field_get:lqc.user.name)
  return _internal_name();
}
inline void user::set_name(const std::string& value) {
  _internal_set_name(value);
  // @@protoc_insertion_point(field_set:lqc.user.name)
}
inline std::string* user::mutable_name() {
  // @@protoc_insertion_point(field_mutable:lqc.user.name)
  return _internal_mutable_name();
}
inline const std::string& user::_internal_name() const {
  return name_.GetNoArena();
}
inline void user::_internal_set_name(const std::string& value) {
  
  name_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
}
inline void user::set_name(std::string&& value) {
  
  name_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:lqc.user.name)
}
inline void user::set_name(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  name_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:lqc.user.name)
}
inline void user::set_name(const void* value, size_t size) {
  
  name_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:lqc.user.name)
}
inline std::string* user::_internal_mutable_name() {
  
  return name_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* user::release_name() {
  // @@protoc_insertion_point(field_release:lqc.user.name)
  
  return name_.ReleaseNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void user::set_allocated_name(std::string* name) {
  if (name != nullptr) {
    
  } else {
    
  }
  name_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), name);
  // @@protoc_insertion_point(field_set_allocated:lqc.user.name)
}

// -------------------------------------------------------------------

// getFriendsRequest

// uint32 id = 1;
inline void getFriendsRequest::clear_id() {
  id_ = 0u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 getFriendsRequest::_internal_id() const {
  return id_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 getFriendsRequest::id() const {
  // @@protoc_insertion_point(field_get:lqc.getFriendsRequest.id)
  return _internal_id();
}
inline void getFriendsRequest::_internal_set_id(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  
  id_ = value;
}
inline void getFriendsRequest::set_id(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _internal_set_id(value);
  // @@protoc_insertion_point(field_set:lqc.getFriendsRequest.id)
}

// -------------------------------------------------------------------

// getFriendsResponse

// repeated .lqc.user friends = 1;
inline int getFriendsResponse::_internal_friends_size() const {
  return friends_.size();
}
inline int getFriendsResponse::friends_size() const {
  return _internal_friends_size();
}
inline void getFriendsResponse::clear_friends() {
  friends_.Clear();
}
inline ::lqc::user* getFriendsResponse::mutable_friends(int index) {
  // @@protoc_insertion_point(field_mutable:lqc.getFriendsResponse.friends)
  return friends_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::lqc::user >*
getFriendsResponse::mutable_friends() {
  // @@protoc_insertion_point(field_mutable_list:lqc.getFriendsResponse.friends)
  return &friends_;
}
inline const ::lqc::user& getFriendsResponse::_internal_friends(int index) const {
  return friends_.Get(index);
}
inline const ::lqc::user& getFriendsResponse::friends(int index) const {
  // @@protoc_insertion_point(field_get:lqc.getFriendsResponse.friends)
  return _internal_friends(index);
}
inline ::lqc::user* getFriendsResponse::_internal_add_friends() {
  return friends_.Add();
}
inline ::lqc::user* getFriendsResponse::add_friends() {
  // @@protoc_insertion_point(field_add:lqc.getFriendsResponse.friends)
  return _internal_add_friends();
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::lqc::user >&
getFriendsResponse::friends() const {
  // @@protoc_insertion_point(field_list:lqc.getFriendsResponse.friends)
  return friends_;
}

// .lqc.resCode res = 2;
inline bool getFriendsResponse::_internal_has_res() const {
  return this != internal_default_instance() && res_ != nullptr;
}
inline bool getFriendsResponse::has_res() const {
  return _internal_has_res();
}
inline void getFriendsResponse::clear_res() {
  if (GetArenaNoVirtual() == nullptr && res_ != nullptr) {
    delete res_;
  }
  res_ = nullptr;
}
inline const ::lqc::resCode& getFriendsResponse::_internal_res() const {
  const ::lqc::resCode* p = res_;
  return p != nullptr ? *p : *reinterpret_cast<const ::lqc::resCode*>(
      &::lqc::_resCode_default_instance_);
}
inline const ::lqc::resCode& getFriendsResponse::res() const {
  // @@protoc_insertion_point(field_get:lqc.getFriendsResponse.res)
  return _internal_res();
}
inline ::lqc::resCode* getFriendsResponse::release_res() {
  // @@protoc_insertion_point(field_release:lqc.getFriendsResponse.res)
  
  ::lqc::resCode* temp = res_;
  res_ = nullptr;
  return temp;
}
inline ::lqc::resCode* getFriendsResponse::_internal_mutable_res() {
  
  if (res_ == nullptr) {
    auto* p = CreateMaybeMessage<::lqc::resCode>(GetArenaNoVirtual());
    res_ = p;
  }
  return res_;
}
inline ::lqc::resCode* getFriendsResponse::mutable_res() {
  // @@protoc_insertion_point(field_mutable:lqc.getFriendsResponse.res)
  return _internal_mutable_res();
}
inline void getFriendsResponse::set_allocated_res(::lqc::resCode* res) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == nullptr) {
    delete res_;
  }
  if (res) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena = nullptr;
    if (message_arena != submessage_arena) {
      res = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, res, submessage_arena);
    }
    
  } else {
    
  }
  res_ = res;
  // @@protoc_insertion_point(field_set_allocated:lqc.getFriendsResponse.res)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace lqc

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_friends_2eproto